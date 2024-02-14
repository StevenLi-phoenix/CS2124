#!/bin/zsh

force=0
while getopts "f" opt; do
  case ${opt} in
    f)
      force=1
      ;;
    \?)
      echo "Invalid option: -$OPTARG" 1>&2
      exit 1
      ;;
  esac
done
shift $((OPTIND -1))

for file in "$@"; do
    if [ ! -f "$file" ]; then
        echo "Error: File '$file' not found."
        exit 1
    fi
    echo "File $file"
done

if [ "$#" -lt 1 ]; then
    echo "please at least provide one file as input"
    exit 1
fi

if git status &> /dev/null; then
    echo "Git commiting..."
    git add . &> /dev/null
    git commit -m "auto commit" &> /dev/null
fi

filename="$1"

if [ ! -f "$filename" ]; then
    echo "Error: File '$filename' not found."
    exit 1
fi

if [ ! -d ".temp" ]; then
    mkdir .temp
fi

current_md5=$(md5 -q "$filename")
last_md5=""
if [ -f ".temp/md5" ]; then
    last_md5=$(cat .temp/md5)
fi

if [ "$current_md5" != "$last_md5" ] || [ $force -eq 1 ]; then
    rm -f .temp/md5
    echo "Compiling..."
    g++ -std=c++11 -Wall "$filename" -o "./.temp/a"
    if [ $? -ne 0 ]; then
        echo "Compilation failed."
        exit 1
    fi
    du -sh "./.temp/a"
    echo "$current_md5" > .temp/md5
fi

if [ "$current_md5" = "$last_md5" ]; then
    echo "Not Modified."
fi

echo "Running...\n"

# run the complied program while copying the input to .temp/input
# copy the output to .temp/output
./.temp/a
# ./.temp/a < input.txt > .temp/output


if [ $? -ne 0 ]; then
    echo "\nExecution failed."
    exit 1
fi

echo "\nDone."

if [ ! "$current_md5" = "$last_md5" ] || [ $force -eq 1 ]; then
    # remote server check complie capability
    echo "Sending files to server"
    for file in "$@"; do
        rsync "./$file" "digit:~/cpp/"
    done
    echo "Compiling and Runninig on server"
    ssh digit "echo complie: > ~/cpp/result.log && g++ ~/cpp/$filename -o ~/cpp/temp.out >> ~/cpp/result.log 2>&1 && echo >> ~/cpp/result.log  && echo run: >> ~/cpp/result.log && cd ~/cpp && ~/cpp/temp.out >> ~/cpp/result.log 2>&1"
    echo "Retrive result"
    rsync digit:~/cpp/result.log ./result.log
    ssh digit "rm ~/cpp/temp.out ~/cpp/result.log"
    echo "Remote Program Out:"
    echo
    cat ./result.log
    echo
fi

