# -*- coding: utf-8 -*-

# Reading inputs
a = float(input())
b = float(input())
c = float(input())

if a >= (b + c) or b >= (a + c) or c >= (a + b):
    print("Valores inválidos na entrada.")
elif a <= 0 or b <= 0 or c <= 0:
    print("Valores inválidos na entrada.")
else:
    if b >= a and b >= c:
        tmp = a
        a = b
        b = tmp
    elif c >= a and c >= b:
        tmp = a
        a = c
        c = tmp

    # Triângulo equilátero.
    if a == b and a == c:
        print("Triângulo equilátero.")
    # Triângulo isósceles.
    elif (a == b != c) or (a == c != b) or (b == c != a):
        print("Triângulo isósceles.")
    # Triângulo escaleno.
    elif a != b != c:
        print("Triângulo escaleno.")

    # Triângulo acutângulo.
    if a**2 < (b**2 + c**2):
        print("Triângulo acutângulo.")
    # Triângulo retângulo.
    elif a**2 == (b**2 + c**2):
        print("Triângulo retângulo.")
    # Triângulo obtusângulo.
    elif a**2 > (b**2 + c**2):
        print("Triângulo obtusângulo.")
