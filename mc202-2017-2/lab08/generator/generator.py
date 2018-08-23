import random
from random import randint

def random_with_N_digits(n):
    range_start = 10**(n-1)
    range_end = (10**n)-1
    return randint(range_start, range_end)


def new_num(d_min=1, d_max=10000):
    n_digits = randint(d_min, d_max)
    sign = random.choice ([-1,1])
    return sign * random_with_N_digits(n_digits)

def new_operation(file, d_min=1, d_max=10000, last_op=0):
    op = randint(0, 3)
    while (last_op == 3 and op == 3):
        op = randint(0, 3)

    if (op == 0):
        op_s = "+"
        num = new_num(d_min, d_max)
        file.write("{} {}\n".format(op_s, num))
    elif (op == 1):
        op_s = "-"
        num = new_num(d_min, d_max)
        file.write("{} {}\n".format(op_s, num))
    elif (op == 2):
        op_s = "*"
        num = new_num(d_min, d_max)
        file.write("{} {}\n".format(op_s, num))
    elif (op == 3):
        op_s = "i"
        file.write("{}\n".format(op_s))

    return op

n_examples = 15
MAX_D = 10000
MAX_OP = 50
path = "../testes_abertos"



for i in range(n_examples):
    filename = "%s/arq%02d.in" % (path, i + 1)
    d_min = 1
    d_max = min(2**(i+1), MAX_D)

    with open(filename, 'w') as file:
        first_n = new_num(d_min, d_max)
        o_min = max(int(((i) * MAX_OP)/n_examples), 1)
        o_max = min(int(((i+2) * MAX_OP)/n_examples), MAX_OP)

        print(filename, d_min, d_max, o_min, o_max)

        n_ops = randint(o_min, o_max)

        file.write("{}\n".format(first_n))
        file.write("{}\n".format(n_ops))

        op = 0
        for j in range(n_ops):
            op = new_operation(file, d_min, d_max, op)
