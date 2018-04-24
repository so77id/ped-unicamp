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
import codecs

i = 1
testfile = "arq" + str(i) +".in"

# Mudando o diretorio atual para o diretorio do script
os.chdir(os.path.dirname(os.path.abspath(__file__)) + "\\")

while (os.path.exists(testfile)) :
    resfile = "arq" + str(i) +".res"
    if not os.path.exists(resfile) :
      print("Arquivo ", resfile, "inexistente.")
      sys.exit()
      
    outfile = "arq" + str(i) +".out"
    outfileUTF8 = "arq" + str(i) + "-utf8.out"
    if (os.path.exists(outfile)) :
       answer = input("Arquivo " + outfile + " existente. Pode ser sobrescrito (S/n) ?")
       if answer == "n" or answer == "N" :
        sys.exit()

    difffile = "arq" + str(i) +".diff"
    if (os.path.exists(difffile)) :
       answer = input("Arquivo " + difffile + " existente. Pode ser sobrescrito (S/n) ?")
       if answer == "n" or answer == "N" :
         sys.exit()
         
    os.system("py main.py < " + testfile + " > " + outfile)

    # Convertendo o arquivo ANSI gerado pelo terminal do Windows em UTF-8
    #     para ser utilizado no File Compare (FC)
    BLOCKSIZE = os.path.getsize(outfile) # or some other, desired size in bytes
    with codecs.open(outfile, "r", "ansi") as sourceFile:
       with codecs.open(outfileUTF8, "w", "utf-8") as targetFile:
         while True:
            contents = sourceFile.read(BLOCKSIZE)
            if not contents:
                break
            targetFile.write(contents)

    if os.system("FC " + resfile + " " + outfileUTF8 + " > " + difffile) == 0 :
       print("Teste ", str(i), ": resultado correto")
    else: 
      print("Teste ", str(i), ": resultado incorreto")
      os.system("type " + difffile)
    os.remove(outfile)
    os.remove(outfileUTF8)
    os.remove(difffile)
    i += 1
    testfile = "arq" + str(i) +".in"
