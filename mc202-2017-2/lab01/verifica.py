#! /usr/bin/env python3

import sys

file_in  = open(str(sys.argv[1]), 'r')
file_res = open(str(sys.argv[2]), 'r')


S = set([int(i) for i in file_res.readline().split()])
R = set([])

file_in.readline()

for i in range(0, 2):
	line = file_in.readline().split()
	A = set([int(i) for i in line[0:]])
	R = R ^ A

if (S != R):
	diffSR = S-R
	diffRS = R-S
	print("S: solução do aluno")
	print("R: solução esperada")
	print("S-R = " + (str(diffSR) if len(diffSR) != 0 else "{}"))
	print("R-S = " + (str(diffRS) if len(diffRS) != 0 else "{}"))
	sys.exit(1)

sys.exit(0)
