#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph {
    int **M;
    int *weigths;
    int n_nodes;
    int n;
} Graph;

typedef Graph * p_graph;


p_graph create_graph(int n_nodes);
void delete_graph(p_graph g);
void add_connection(p_graph g, int a, int b);
void add_weigth(p_graph g, int w);
void print_entediado(p_graph g);

#endif
