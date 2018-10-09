import operator

d = {}
while 1:
    op = raw_input().split(' ')
    if op[0] == "#":
        break

    name, w = op
    d[int(w)] = name

    sorted_x = sorted(d.items(), key=operator.itemgetter(0))
    # print(sorted_x)
    # sorted_x = sorted(d.items(), key=lambda(k, v): (-v, k))
    l = len(sorted_x)
    if l % 2 != 0:
        print "{}: {}".format(sorted_x[l//2][1], sorted_x[l//2][0])
    else:
        print "{}: {}".format(sorted_x[(l//2) - 1][1], sorted_x[(l//2) - 1][0])
        print "{}: {}".format(sorted_x[l//2][1], sorted_x[l//2][0])
