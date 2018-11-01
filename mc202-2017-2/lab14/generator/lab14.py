def entediado(a, b, c):
    sum = float(a+b+c)/3.0
    if sum <= float(2.0*a) and sum <= float(2.0*b) and sum <= float(2.0*c):
        return False
    else:
        return True


inp = raw_input().split(" ")

n_nodes = int(inp[0])
n_con = int(inp[1])

w_list = []

w_s = raw_input().split(" ")

for w in w_s:
    w = int(w)
    w_list.append(w)

e_list = [0 for i in range(n_nodes)]
graph = [[0 for j in range(n_nodes)] for i in range(n_nodes)]

for i in range(n_con):
    inp = raw_input().split(" ")
    a = int(inp[0])
    b = int(inp[1])

    graph[a][b] = 1
    graph[b][a] = 1

for i in range(n_nodes):
    for j in range(i+1, n_nodes):
        if graph[i][j] == 0:
            continue
        for k in range(j+1, n_nodes):
            if graph[i][k] == 0 or graph[j][k] == 0:
                continue
            if entediado(w_list[i], w_list[j], w_list[k]):
                e_list[i] = 1
                e_list[j] = 1
                e_list[k] = 1
for i in range(n_nodes):
    if  e_list[i] == 1:
        print(i)
