#!/bin/bash
search_dir=./testes_abertos


cd /usr/src/myapp/lab04
arqlist=(
         "arq01"
         "arq02"
         "arq03"
         "arq04"
         "arq05"
         "arq06"
         "arq07"
         "arq08"
         "arq09"
         "arq10"
         "arq11"
         "arq12"
         "arq13"
         "arq14"
         "arq15"
         "arq16"
         "arq17"
         "arq18"
         "arq19"
         "arq20"
         "arq21"
         "arq22"
         "arq23"
         "arq24"
         "arq25"
         "arq26"
         "arq27"
         "arq28"
         "arq29"
         "arq30"
)

## now loop through the above array
for i in "${arqlist[@]}"
do
   ./lab04 < $search_dir/$i.in > $search_dir/$i.res
   # or do whatever with individual element of the array
done
