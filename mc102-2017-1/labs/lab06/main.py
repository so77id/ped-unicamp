# -*- coding: utf-8 -*-


def add_to_person_dict(dict, state_dict, person, type='i|a|d'):
    if person in dict:
        # inocent
        if type == "d" and dict[person] != "d":
            dict[person] = "d"
        elif type == "a" and dict[person] == "i":
            dict[person] = "a"
    else:
        state_dict[person] = True
        dict[person] = type
    return dict


def print_name(name, state, type):
    if type == 'd':
        type_str = "detetive"
    elif type == 'i':
        type_str = "vítima inocente"
    elif type == 'a':
        type_str = "assassino(a)"

    if state:
        state_str = ""
    else:
        state_str = " (in memoriam)"

    print("{}{}: {}.".format(name, state_str, type_str))


def print_assasin(assasins_list, name, people_dict):
    assasins = []
    detectives = []
    inocents = []
    for victim in assasins_list:
        if people_dict[victim] == "d":
            detectives.append(victim)
        elif people_dict[victim] == "a":
            assasins.append(victim)
        elif people_dict[victim] == "i":
            inocents.append(victim)

    if len(detectives) > 0:
        print("  Matou {} detetive(s).".format(len(detectives)))

    if len(assasins) > 0:
        print("  Matou {} assassinos(s).".format(len(assasins)))

    if len(inocents) > 0:
        print("  Matou {} inocente(s).".format(len(inocents)))


def print_detective(detective_list, name):
    print("  Resolveu {} caso(s).".format(len(detective_list)))


def main():
    lines = int(input())
    if lines < 1 or lines > 100:
        print("Valor inválido na entrada.")
        return

    assasins_dict = {}
    detectives_dict = {}
    people_dict = {}
    state_dict = {}

    for l in range(lines):
        inp = input().split(" ")
        # print(inp, inp.split(" "))
        assasin = inp[0]
        victim = inp[1]
        detective = inp[2]
        if assasin not in assasins_dict:
            assasins_dict[assasin] = [victim]
        else:
            assasins_dict[assasin].append(victim)

        if detective not in detectives_dict:
            detectives_dict[detective] = [assasin]
        else:
            detectives_dict[detective].append(assasin)

        add_to_person_dict(people_dict, state_dict, assasin, 'a')
        add_to_person_dict(people_dict, state_dict, victim, 'i')
        add_to_person_dict(people_dict, state_dict, detective, 'd')

        state_dict[victim] = False

    people_list = list(people_dict.keys())
    people_list.sort()

    for p in people_list:

        print("------------------------------------------------------------")
        print_name(p, state_dict[p], people_dict[p])

        if p in detectives_dict:
            print_detective(detectives_dict[p], p)

        if p in assasins_dict:
            print_assasin(assasins_dict[p], p, people_dict)

        # if people_dict[p] == 'a':
        #     print_assasin(assasins_dict[p], p, people_dict)

    print("------------------------------------------------------------")


if __name__ == "__main__":
    main()
