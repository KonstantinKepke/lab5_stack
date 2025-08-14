#/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

#set -x
#set -e

# $2 - dir name
function make_clear_and_run(){
    echo "make_clear_and_run with params $1"
    if [[ -z $1 ]] ; then
        echo "Dirname for make not defined\n"
        exit 1
    fi
    pushd $1
    # echo "pwd = "
    # pwd
    make -f makefile
    echo "result of make is $?"
    popd

    echo "make_clear_and_run with params ended"
    exit 0
}
#
# main
#
#echo -e "${GREEN} Start $1 with params $@.${NC}"



echo -e "${GREEN}Start $0 with params $1 and Cpp_std = $STD ${NC}"

if [[ $1 == "make" ]]; then  
    make_clear_and_run $2
fi

STD=${2:-c++20}

rm -rf $1.bin

echo -e "build $1 ..."
g++ -lfmt --std=$STD -O0 -o $1.bin $1


echo -e "\n\033[0;32m-> Run $1.bin :\033[0;37m"
${PWD}/$1.bin

#echo " RUN   =---> $?"
if [[ $? == 0 ]] ; then
    echo -e "\n\033[0;32m1 End run with errcode= $? \033[0;37m"
else
    echo -e "\n\033[0;31m2 End run with errcode= $? \033[0;37m"
fi
