

def type_of_slug(vel):
    if vel < 10:
        return 1
    elif vel < 20:
        return 2
    else:
        return 3


n_case = int(input())
if n_case > 100:
    print("Valor inválido na linha 1.")
    exit()

max_type = 0
for i in range(n_case):
    vel = int(input())
    if vel > 50:
        print("Valor inválido na linha {}.".format(i + 2))
        exit()
    type = type_of_slug(vel)
    if type > max_type:
        max_type = type

print(max_type)
