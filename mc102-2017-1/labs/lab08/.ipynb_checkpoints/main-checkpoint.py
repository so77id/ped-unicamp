def diagonals(m):
    """
    https://stackoverflow.com/a/31373955/190597 (unutbu)
    >>> m = array([[ 0,  1,  2],
                   [ 3,  4,  5],
                   [ 6,  7,  8],
                   [ 9, 10, 11]])

    >>> diagonals(m)
    [[9], [6, 10], [3, 7, 11], [0, 4, 8], [1, 5], [2]]
    """
    h, w = len(m), len(m[0])
    diags = [[m[h - p + q - 1][q] for q in range(max(p-h+1, 0), min(p+1, w))] for p in range(h + w - 1)]
    coords = [[ (h - p + q - 1,q) for q in range(max(p-h+1, 0), min(p+1, w))] for p in range(h + w - 1)]

    return diags, coords


def antidiagonals(m):
    """
    >>> m = array([[ 0,  1,  2],
                   [ 3,  4,  5],
                   [ 6,  7,  8],
                   [ 9, 10, 11]])

    >>> antidiagonals(m)
    [[0], [3, 1], [6, 4, 2], [9, 7, 5], [10, 8], [11]]
    """
    h, w = len(m), len(m[0])
    anti_diags = [[m[p - q][q] for q in range(max(p-h+1,0), min(p+1, w))] for p in range(h + w - 1)]
    coords = [[(p - q, q) for q in range(max(p-h+1,0), min(p+1, w))] for p in range(h + w - 1)]
    return anti_diags, coords

def print_map(map):
    for i in range(len(map)):
            print(' '.join(str(e) for e in map[i]))

def find_horizontal(map, word):
    c = 0
    max_count = len(word)
    coords = []

    for i in range(len(map)):
        for j in range(len(map[i])):
            if c == max_count:
                break
            if word[c] == map[i][j]:
                c +=1
                coords.append((i,j))
            elif c > 0:
                c = 0
                coords =[]
    if c != max_count:
        return False, []
    else:
        return True, coords

def find_horizontal_reversed(map, word):
    c = 0
    max_count = len(word)
    coords = []

    for i in reversed(range(len(map))):
        for j in reversed(range(len(map[i]))):
            if c == max_count:
                break
            if word[c] == map[i][j]:
                c +=1
                coords.append((i,j))
            elif c > 0:
                c = 0
                coords =[]
    if c != max_count:
        return False, []
    else:
        return True, coords


def find_vertical(map, word):
    c = 0
    max_count = len(word)
    coords = []

    for i in range(len(map[0])):
        for j in range(len(map)):
            if c == max_count:
                break
            if word[c] == map[j][i]:
                c +=1
                coords.append((j,i))
            elif c > 0:
                c = 0
                coords =[]
    if c != max_count:
        return False, []
    else:
        return True, coords


def find_vertical_reversed(map, word):
    c = 0
    max_count = len(word)
    coords = []

    for i in reversed(range(len(map[0]))):
        for j in reversed(range(len(map))):
            if c == max_count:
                break
            if word[c] == map[j][i]:
                c +=1
                coords.append((j,i))
            elif c > 0:
                c = 0
                coords =[]
    if c != max_count:
        return False, []
    else:
        return True, coords

def find_diagonal(map, word):
    c = 0
    max_count = len(word)
    coords = []
    diags, d_coords = diagonals(map)

    for i in range(len(diags)):
        for j in range(len(diags[i])):
            if c == max_count:
                break
            if word[c] == diags[i][j]:
                c +=1
                coords.append(d_coords[i][j])
            elif c > 0:
                c = 0
                coords =[]
    if c != max_count:
        return False, []
    else:
        return True, coords

def find_diagonal_reversed(map, word):
    c = 0
    max_count = len(word)
    coords = []
    diags, d_coords = diagonals(map)

    for i in range(len(diags)):
        for j in reversed(range(len(diags[i]))):
            if c == max_count:
                break
            if word[c] == diags[i][j]:
                c +=1
                coords.append(d_coords[i][j])
            elif c > 0:
                c = 0
                coords =[]
    if c != max_count:
        return False, []
    else:
        return True, coords


def find_antidiagonal(map, word):
    c = 0
    max_count = len(word)
    coords = []
    anti_diag, d_coords = antidiagonals(map)

    for i in range(len(anti_diag)):
        for j in range(len(anti_diag[i])):
            if c == max_count:
                break
            if word[c] == anti_diag[i][j]:
                c +=1
                coords.append(d_coords[i][j])
            elif c > 0:
                c = 0
                coords =[]
    if c != max_count:
        return False, []
    else:
        return True, coords

def find_antidiagonal_reversed(map, word):
    c = 0
    max_count = len(word)
    coords = []
    anti_diag, d_coords = antidiagonals(map)

    for i in range(len(anti_diag)):
        for j in reversed(range(len(anti_diag[i]))):
            if c == max_count:
                break
            if word[c] == anti_diag[i][j]:
                c +=1
                coords.append(d_coords[i][j])
            elif c > 0:
                c = 0
                coords =[]
    if c != max_count:
        return False, []
    else:
        return True, coords


def find_word(map, word):
    word_list = list(word)
    coords = []

    # Horizontal
    find, coords = find_horizontal(map, word_list)
    if find:
        return coords

    # Horizontal reversed
    find, coords = find_horizontal_reversed(map, word_list)
    if find:
        return coords


    # Vertical
    find, coords = find_vertical(map, word_list)
    if find:
        return coords

    # Vertical reversed
    find, coords = find_vertical_reversed(map, word_list)
    if find:
        return coords

    # Diagonal
    find, coords = find_diagonal(map, word_list)
    if find:
        return coords

    # Diagonal reversed
    find, coords = find_diagonal_reversed(map, word_list)
    if find:
        return coords

    # Antidiagonal
    find, coords = find_antidiagonal(map, word_list)
    if find:
        return coords

    # Antidiagonal reversed
    find, coords = find_antidiagonal_reversed(map, word_list)
    if find:
        return coords


    return []

def paint_word(map_, map, coords):
    for (i,j) in coords:
        map_[i][j] = map[i][j]


m = []

while True:
    l = input()
    if l.isdigit():
        n = int(l)
        break
    else:
        l = l.split()
        m.append(l)

m_ = [["." for x in range(len(m[y]))] for y in range(len(m))]
words = []
for i in range(n):
    word = input()
    words.append(word)


for word in words:
    coords = find_word(m, word)
    paint_word(m_, m, coords)

print_map(m_)
