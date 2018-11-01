import random

# path = "../testes_abertos"
path = "../testes_fechados"

MIN_AGE=10
MAX_AGE=120
MIN_P=8
MAX_P=500

MIN_FACTOR=0
MAX_FACTOR=1

MIN_C_FACTOR=2
MAX_C_FACTOR=10

N_EXAMPLES=10

def order(a,b):
    if a > b:
        return (b, a)
    else:
        return (a, b)


for i in range(N_EXAMPLES):
    p_min = min(max(2**(i+MIN_FACTOR), MIN_P), MAX_P)
    p_max = min(max(2**(i+MAX_FACTOR), MIN_P), MAX_P)
    print("p_min: {}, p_max: {}".format(p_min, p_max))

    n_people = random.randint(p_min, p_max)
    filename = "%s/arq%02d.in" % (path, i + 1)

    c_min = min(int(n_people*MIN_C_FACTOR), n_people*(n_people-1)//2)
    c_max = min(int(n_people*MAX_C_FACTOR), n_people*(n_people-1)//2)
    n_conections = random.randint(c_min, c_max)

    print("filename: {} p_min: {}, p_max: {},  n_people: {}, \n\t  c_min: {}, c_max: {},  n_conections: {}".format(filename, p_min, p_max, n_people, c_min, c_max, n_conections))

    p_list = []
    graph = [[0 for k in range(n_people)] for j in range(n_people)]
    c_list = []

    for j in range(n_people):
        age = random.randint(MIN_AGE, MAX_AGE)
        p_list.append(age)


    # cont = 0

    pos_con = []
    for j in range(n_people):
        for k in range(j+1, n_people):
            pos_con.append((j,k))

    print len(pos_con)
    for j in range(n_conections):
        k = random.randint(0,len(pos_con)-1)
        c_list.append(pos_con[k])
        del pos_con[k]
    # while cont < n_conections:
    #     # k = random.randint(0, n_people-1)
    #     # j = random.randint(0, n_people-1)
    #     # if k >= n_people or j >= n_people:
    #     #     continue
    #     # if k == j:
    #     #     continue
    #     #
    #     # (a,b) = order(k, j)
    #     # if (a,b) in c_list:
    #     #     continue
    #     # else:
    #     #     print "cont:", cont, "insert:", (a,b)
    #     #     c_list.append((a,b))
    #         cont+=1

    c_list.sort()

    with open(filename, 'w') as file:
        file.write("{} {}\n".format(n_people, len(c_list)))
        for p in range(len(p_list)):
            if p+1 == len(p_list):
                file.write("{}\n".format(p_list[p]))
            else:
                file.write("{} ".format(p_list[p]))
        for (a,b) in c_list:
            file.write("{} {}\n".format(a, b))
