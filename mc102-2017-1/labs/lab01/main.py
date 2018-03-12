
type_op_1 = input()

if type_op_1 == "f":
    n1 = float(input())
elif type_op_1 == "i":
    n1 = int(input())

type_op_2 = input()

if type_op_2 == "f":
    n2 = float(input())
elif type_op_2 == "i":
    n2 = int(input())

if type_op_2 == "f" or type_op_1 == "f":
    print(format((n1 + n2), ".2f"))
else:
    print((n1 + n2))