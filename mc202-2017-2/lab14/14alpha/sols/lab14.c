#include <stdio.h>

#include "grafo.h"


int main(int argc, char const *argv[]) {
    int n_nodes, n_con, i, w, a, b;
    p_graph g;

    scanf("%d %d", &n_nodes, &n_con);

    g = create_graph(n_nodes);

    for (i = 0; i < n_nodes; i++) {
        scanf("%d ", &w);
        add_weigth(g, w);
    }

    for (i = 0; i < n_con; i++) {
        scanf("%d %d", &a, &b);
        add_connection(g, a, b);
    }

    print_entediado(g);

    return 0;
}
