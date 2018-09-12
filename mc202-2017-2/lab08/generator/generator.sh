#!/bin/bash
# search_dir=../testes_fechados
search_dir=../testes_abertos


cd /src/lab08/generator

# python generator.py

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
)

## now loop through the above array
for i in "${arqlist[@]}"
do
   python lab08.py < $search_dir/$i.in > $search_dir/$i.res
   # or do whatever with individual element of the array
done
