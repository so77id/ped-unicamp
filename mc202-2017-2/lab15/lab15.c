#include <stdio.h>

void clean_nodes(int *nodes, int n_nodes) {
    int i;

    for (i = 0; i < n_nodes; i++) {
        nodes[i] = 0;
    }
}


int main(int argc, char const *argv[]) {
    int n_nodes, n_groups, size_group, node, i, j, k, *nodes, cont;
    p_graph graph;

    scanf("%d %d", &n_nodes, &n_groups);

    graph = create_graph(n_nodes);
    nodes = malloc(n_nodes * sizeof(int));

    for (i = 0; i < n_groups; i++) {
        cont = 0;
        scanf("%d", &size_group);
        for (j = 0; j < size_group; j++) {
            scanf("%d", &node);
            nodes[j] = node;
            cont++;
        }

        for (j = 0; j < cont; j++) {
            for (k = j+1; k < cont; k++) {
                add_connection(graph, nodes[j], nodes[k]);
            }
        }
    }

    summary_graph(graph);

    return 0;
}
