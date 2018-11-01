#include <stdlib.h>
#include <stdio.h>

#include "graph.h"


p_graph create_graph(int n_nodes) {
    int i, j;

    p_graph g = malloc(sizeof(Graph));
    g->M = malloc(n_nodes * sizeof(int *));
    g->weigths = malloc(n_nodes * sizeof(int));
    g->n_nodes = n_nodes;
    g->n = 0;

    for (i = 0; i < n_nodes; i++) {
        g->M[i] = malloc(n_nodes * sizeof(int));
        for (j = 0; j < n_nodes; j++) {
            g->M[i][j] = 0;
        }
    }

    return g;
}


void delete_graph(p_graph g){
    int i;

    for (i = 0; i < g->n_nodes; i++) {
        free(g->M[i]);
    }
    free(g->M);
    free(g->weigths);
    free(g);
}

void add_connection(p_graph g, int a, int b) {
    g->M[a][b] = g->M[b][a] = 1;
}

void add_weigth(p_graph g, int w) {
    g->weigths[g->n++] = w;
}


int entediado(int a, int b, int c) {
    float prom = (a+b+c)/3.0;

    if(prom <= 2*a && prom <= 2*b && prom <= 2*c) return 0;
    else  return 1;
}

void print_entediado(p_graph g) {
    int *e_list, i, j, k;

    e_list = malloc(g->n_nodes * sizeof(int));
    for (i = 0; i < g->n_nodes; i++) {
        e_list[i] = 0;
    }

    for (i = 0; i < g->n_nodes; i++) {
        for (j = i+1; j < g->n_nodes; j++) {
            if (!g->M[i][j]) continue;
            for (k = j+1; k < g->n_nodes; k++) {
                if(!g->M[i][k] || !g->M[j][k]) continue;
                if(entediado(g->weigths[i], g->weigths[j], g->weigths[k]))
                {
                    e_list[i] = 1;
                    e_list[j] = 1;
                    e_list[k] = 1;
                }
            }
        }
    }

    for (i = 0; i < g->n_nodes; i++) {
        if(e_list[i]) printf("%d\n", i);
    }
}
