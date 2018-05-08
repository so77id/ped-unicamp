# -*- coding: utf-8 -*-
#
# Script para testar tarefas de laboratório de MC102.

# O programa main.py será testado com todos os arquivos arq<i>.in
# encontrados no diretório corrente. Os testes serão iniciados com i
# igual a 1 e serão interrompidos quando arq<i>.in não for encontrado.

# As saídas serão comparadas com os arquivos arquivos arq<i>.res. 

# Durante o processamento serão criados e posteriormente removidos
# arquivos arq<i>.out e arq<i>.diff. 

# Script modificado por Sergio Arnosti e Alexandre Gomes (Laboratorio LMCAD)
# 	Foi acrescentada a conversão do arquivo ANSI gerado pelo windows para UTF-8
#   e também a codificação byte a byte (decodelocao) para arrumar problema com acentos na
#   na codificação cp1252.

import os
import sys
import codecs

# Se é possivel fazer o decoding com cp1252 ou utf-8, retorna o valor r decodificado,
#   caso contrário mantém o valor.
def decodelocao(w):
    encodes = ('utf-8', 'cp1252')
    
    r = w
    for e in encodes:
        try:
            r = r.decode(e)
            #print(r)
            return r
        except Exception as ex:
            #print(ex)
            continue
    return str(r)
	
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
         
    os.system("python main.py < " + testfile + " > " + outfile)

    # Convertendo o arquivo ANSI gerado pelo terminal do Windows em UTF-8
    #     para ser utilizado no File Compare (FC)
    #BLOCKSIZE = os.path.getsize(outfile) # or some other, desired size in bytes
    with codecs.open(outfile, "r") as sourceFile:
        with codecs.open(outfileUTF8, "w", "utf-8") as targetFile:
            for l in sourceFile:
                l2 = ""
                words = l.split(' ')
                for w in range(len(words)):
                    if words[w] == '':
                        l2 += ' '  
                    else:
                        if w < len(words)-1:
                            l2 += decodelocao(bytes(words[w], 'cp1252')) + ' '
                        else:
                            l2 += decodelocao(bytes(words[w], 'cp1252'))
							
                targetFile.write(l2)

    exec_code = os.system("FC " + resfile + " " + outfileUTF8 + " > " + difffile)
    if exec_code == 0 :
       print("Teste ", str(i), ": resultado correto")
    else: 
      print("Teste ", str(i), ": resultado incorreto (Code: {})".format(exec_code))
      os.system("type " + difffile)
    os.remove(outfile)
    os.remove(outfileUTF8)
    os.remove(difffile)
    i += 1
    testfile = "arq" + str(i) +".in"
