# -*- coding: utf-8 -*-
#
# Script para testar tarefas de laboratório de MC102.

# O programa main.py será testado com todos os arquivos arq<i>.in
# encontrados no diretório corrente. Os testes serão iniciados com i
# igual a 1 e serão interrompidos quando arq<i>.in não for encontrado.

# As saídas serão comparadas com os arquivos arquivos arq<i>.res. 

# Durante o processamento serão criados e posteriormente removidos
# arquivos arq<i>.out e arq<i>.diff. 

import os
import sys

i = 1
testfile = "arq" + str(i) +".in"

while (os.path.exists(testfile)) :
    resfile = "arq" + str(i) +".res"
    if not os.path.exists(resfile) :
      print("Arquivo ", resfile, "inexistente.")
      sys.exit()
      
    outfile = "arq" + str(i) +".out"
    if (os.path.exists(outfile)) :
       answer = input("Arquivo " + outfile + " existente. Pode ser sobrescrito (S/n) ?")
       if answer == "n" or answer == "N" :
         sys.exit()
         
    difffile = "arq" + str(i) +".diff"
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
    testfile = "arq" + str(i) +".in"
