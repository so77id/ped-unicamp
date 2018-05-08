# -*- coding: utf-8 -*-
#
# Script para testar tarefas de laboratório de MC102.

# O programa main.py será testado com todos os ./arqs-07/arquivos ./arqs-07/arq<i>.in
# encontrados no diretório corrente. Os testes serão iniciados com i
# igual a 1 e serão interrompidos quando ./arqs-07/arq<i>.in não for encontrado.

# As saídas serão comparadas com os ./arqs-07/arquivos ./arqs-07/arquivos ./arqs-07/arq<i>.res. 

# Durante o processamento serão criados e posteriormente removidos
# ./arqs-07/arquivos ./arqs-07/arq<i>.out e ./arqs-07/arq<i>.diff. 

import os
import sys

i = 1
testfile = "./arqs-07/arq" + str(i) +".in"

while (os.path.exists(testfile)) :
    resfile = "./arqs-07/arq" + str(i) +".res"
    if not os.path.exists(resfile) :
      print("Arquivo ", resfile, "inexistente.")
      sys.exit()

    outfile = "./arqs-07/arq" + str(i) +".out"
    if (os.path.exists(outfile)) :
       answer = input("Arquivo " + outfile + " existente. Pode ser sobrescrito (S/n) ?")
       if answer == "n" or answer == "N" :
         sys.exit()

    difffile = "./arqs-07/arq" + str(i) +".diff"
    if (os.path.exists(difffile)) :
       answer = input("Arquivo " + difffile + " existente. Pode ser sobrescrito (S/n) ?")
       if answer == "n" or answer == "N" :
         sys.exit()

    os.system("python3 main.py < " + testfile + " > " + outfile)
    if os.system("diff " + resfile + " " + outfile + " > " + difffile) == 0 :
       print("Teste ", str(i), ": resultado correto")
    else:
      print("Teste ", str(i), ": resultado incorreto")
      os.system("cat " + difffile)
    os.remove(outfile)
    os.remove(difffile)
    i += 1
    testfile = "./arqs-07/arq" + str(i) +".in"
