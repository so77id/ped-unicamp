
number = int(raw_input())
n_op = int(raw_input())

for i in range(n_op):
    op_s = raw_input().split(' ')
    op = op_s[0]
    if op == "+":
        new_n = int(op_s[1])
        number += new_n
    elif op == "-":
        new_n = int(op_s[1])
        number -= new_n
    elif op == "i":
        number *= -1

    print number
