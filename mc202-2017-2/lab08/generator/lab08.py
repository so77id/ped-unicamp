
number = 0
# n_op = int(raw_input())

while 1:
    op_s = raw_input().split(' ')
    op = op_s[0]
    if op == "#":
        break
    elif op == "+":
        new_n = int(op_s[1])
        number += new_n
    elif op == "-":
        new_n = int(op_s[1])
        number -= new_n
    elif op == "*":
        new_n = int(op_s[1])
        number *= new_n
    elif op == "i":
        number *= -1

    print number
