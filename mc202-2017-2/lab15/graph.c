#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "grafo.h"


p_graph create_graph(int n_nodes) {
    int i, j;

    p_graph g = malloc(sizeof(Graph));
    g->M = malloc(n_nodes * sizeof(int *));
    g->n_nodes = n_nodes;

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
    free(g);
}

void add_connection(p_graph g, int a, int b) {
    g->M[a][b] = g->M[b][a] = 1;
}


void clear_vect(int * vect, int n_nodes, int value) {
    for (i = 0; i < n_nodes; i++) {
        vect[i] = value;
    }
}

void summary_graph(p_graph g) {
    int i, *dist, node, fathers;
    p_stack stack;

    stack = create_stack();
    dist = malloc(g->n_nodes * sizeof(int));
    fathers = malloc(g->n_nodes * sizeof(int));


    for (i = 0; i < g->n_nodes; i++) {
        clear_vect(dist, n_nodes, 0);
        clear_vect(fathers, n_nodes, -1);

        push(stack, i);

        while(!empty(stack)) {
            node = top(stack);
            pop(stack);

            if(fathers[node] == -1){
                dist[node] = 1;
            } else {
                dist[node] = dist[fathers[node]] + 1;
            }

        }
    }

}




p_snode create_snode(int value, p_snode next) {
    p_snode aux = malloc(sizeof(SNode));
    aux->value = value;

    aux->next = next;

    return aux;
}

void delete_snode(p_snode node){
    free(node);
}

p_stack create_stack() {
    p_stack stack = malloc(sizeof(Stack));

    stack->head = NULL;
    return stack;
}

void delete_stack(p_stack stack) {
    p_snode aux, aux_d;

    aux = stack->head;

    while(aux) {
        aux_d = aux;;
        aux = aux->next;

        delete_snode(aux_d);
    }

    free(stack);
}

int empty(p_stack stack) {
    if (stack->head) return 0;
    else return 1;
}

int top(p_stack stack) {
    return stack->head->value;
}

void pop(p_stack stack) {
    p_snode aux;

    if(stack->head) {
        aux = stack->head;
        stack->head = aux->next;

        delete_snode(aux);
    }
}

void push(p_stack stack, int value) {
    stack->head = create_snode(value, stack->head);
}

void print_stack(p_stack stack) {
    p_snode aux = stack->head;
    printf("Print stack:\n");
    while(aux) {
        printf("%d-", aux->value);
        aux = aux->next;
    }
    printf("\n");
}
