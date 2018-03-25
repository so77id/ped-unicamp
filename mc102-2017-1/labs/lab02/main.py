

def load_num():
    str_ = input()

    if str_.isdigit():
        num = int(str_)
        typ = 'i'
    else:
        num = float(str_)
        typ = 'f'

    return num, typ


def main():
    n1, n1_typ = load_num()
    oper = input()
    n2, n2_typ = load_num()


    if (oper == '/' or oper == '//' or oper == '%') and n2 == 0:
        print("Erro.")
    else:
        if oper == '+':
            result = n1 + n2
        elif oper == '-':
            result = n1 - n2
        elif oper == '*':
            result = n1 * n2
        elif oper == '/':
            result = n1 / n2
        elif oper == '//':
            result = n1 // n2
        elif oper == '%':
            result = n1 % n2
        elif oper == '**':
            result = n1 ** n2


        if n1_typ == 'i' and n2_typ == 'i':
            if oper != '/':
                print(result)
            else:
                print(format(result, ".2f"))
        else:
            print(format(result, ".2f"))


if __name__ == '__main__':
    main()