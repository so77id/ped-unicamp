import random
from random import randint

def random_with_N_digits(n):
    range_start = 10**(n-1)
    range_end = (10**n)-1
    return randint(range_start, range_end)


def get_n_digits(n):
    return len(str(n))

def new_num(d_min=1, d_max=10000):
    n_digits = randint(d_min, d_max)
    # sign = random.choice([-1,1])
    return random_with_N_digits(n_digits)


def new_operation(file, a_num, d_min=1, d_max=10000, last_op=0, choices=[0,0,0,0,0,1,1,1,1,1,2,2,2]):
    op = random.choice(choices)
    while (last_op == 3 and op == 3):
        op = random.choice(choices)

    if (op == 0):
        op_s = "+"
        num = new_num(d_min, d_max)
        a_num += num
        file.write("{} {}\n".format(op_s, num))
    elif (op == 1):
        op_s = "-"
        while(1):
            num = new_num(d_min, get_n_digits(a_num))
            if(a_num - num >= 0):
                break
        a_num -=num

        file.write("{} {}\n".format(op_s, num))
    elif (op == 2):
        op_s = "*"
        num = new_num(d_min, d_max)
        a_num *= num
        file.write("{} {}\n".format(op_s, num))
    elif (op == 3):
        op_s = "i"
        a_num *= -1
        file.write("{}\n".format(op_s))

    return op, a_num
init = 7
n_examples = 3 + init
MAX_D = 1000
MAX_OP = 25
path = "../testes_fechados"
choices = [0,0,0,0,2]

num = 0
for i in range(init,n_examples):
    filename = "%s/arq%02d.in" % (path, i + 1)
    d_min = 1
    d_max = min(2**(i+3), MAX_D)

    with open(filename, 'w') as file:
        # first_n = new_num(d_min, d_max)
        o_min = max(int(((i) * MAX_OP)/n_examples), 1)
        o_max = min(int(((i+2) * MAX_OP)/n_examples), MAX_OP)

        print(filename, d_min, d_max, o_min, o_max)

        n_ops = randint(o_min, o_max)

        # file.write("{}\n".format(first_n))
        # file.write("{}\n".format(n_ops))

        op = 0
        for j in range(n_ops):
            if j == 0:
                op, num = new_operation(file, num, d_min, d_max, op, [0])
            else:
                op, num = new_operation(file, num, d_min, d_max, op, choices)
        file.write("#\n")
