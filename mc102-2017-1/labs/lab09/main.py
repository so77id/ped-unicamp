import copy

def review_neighborhood(map, x, y):
    neighbors = 0
    for i in range(-1, 2, 1):
        for j in range(-1, 2, 1):
            if i == j and j == 0:
                continue
            if map[x + i][y + j] == "@":
                neighbors += 1

    return neighbors

def new_epoch(map):
    new_map = copy.deepcopy(map)
    for i, line in enumerate(map):
        if i == 1 or i == len(map)-2:
            continue
        for j, char in enumerate(line):
            if char == "+" or char == "-":
                break
            if char == "|":
                continue
            if j == 1 or j == len(line)-2:
                continue

            neighbors = review_neighborhood(map, i, j)


            if map[i][j] == "@":
                if neighbors < 2:
                    # Dead
                    new_map[i][j] = " "
                elif neighbors > 3:
                    # Dead
                    new_map[i][j] = " "
            elif map[i][j] == " ":
                if neighbors == 3:
                    new_map[i][j] = "@"

    return new_map



def print_maps(maps):
    f_map = maps[0]
    for i in range(len(f_map)):
        lines = []
        for map in maps:
            lines.append(''.join(map[i]))
        print(' '.join(lines))



def print_map(map):
    for line in map:
        for char in line:
            print(char, end="")
        print("")

def main():

    inp = input()
    map = []
    maps = []
    while not inp.isdigit():
        map.append(list(inp))
        inp = input()

    maps.append(map)
    steps = int(inp)
    for i in range(steps):
        map = new_epoch(map)
        maps.append(map.copy())

    print_maps(maps)





if __name__ == "__main__":
    main()
