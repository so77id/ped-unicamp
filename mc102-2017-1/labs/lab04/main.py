# -*- coding: utf-8 -*-


space = ' '


def print_rect_tri(base, s):
    for i in range(1, (base + 1), 2):
        text = i * s
        print(text)


def print_rect_tri_inv(base, s):
    for i in range(base, 0, -2):
        text = i * s
        print(text)


def print_tri_isos(base, s):
    for i in range(1, (base + 1), 2):
        res = (base - i)//2
        text = res * space + i * s
        print(text)


def print_tri_isos_inv(base, s):
    for i in range(base, 0, -2):
        res = (base - i)//2
        text = res * space + i * s
        print(text)


def print_ampulheta(base, s):
    for i in range(base, 0, -2):
        res = (base - i)//2
        text = res * space + i * s
        print(text)
    for i in range(3, (base + 1), 2):
        res = (base - i)//2
        text = res * space + i * s
        print(text)


def print_estrela(base, s):
    for i in range(1, (base - 1), 2):
        res = (base - i)//2 + base
        text = res * space + i * s
        print(text)
    print(3*base * s)

    for i in range(base-2, 0, -2):
        res = (base - i)//2
        tri = res * space + i * s
        text = tri + (res + base) * space + tri
        print(text)

    for i in range(3, (base - 1), 2):
        res = (base - i)//2
        tri = res * space + i * s
        text = tri + (res + base) * space + tri
        print(text)
    print(3*base * s)

    for i in range(base-2, 0, -2):
        res = (base - i)//2 + base
        text = res * space + i * s
        print(text)


def print_fig(type, base, symbol):
    if type == "TR":
        print_rect_tri(base, symbol)
    elif type == "TRI":
        print_rect_tri_inv(base, symbol)
    elif type == "TI":
        print_tri_isos(base, symbol)
    elif type == "TII":
        print_tri_isos_inv(base, symbol)
    elif type == "A":
        print_ampulheta(base, symbol)
    elif type == "E":
        print_estrela(base, symbol)
    else:
        print("Objeto inválido.")


def odd(n):
    if n % 2 == 0:
        return True
    else:
        return False


def main():
    type = input()
    base = int(input())
    symbol = input()

    if odd(base):
        print("Base inválida.")
    else:
        print_fig(type, base, symbol)

    return 0


if __name__ == '__main__':
    main()
