#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph {
    int **M;
    int n_nodes;
} Graph;

typedef Graph * p_graph;


p_graph create_graph(int n_nodes);
void delete_graph(p_graph g);
void add_connection(p_graph g, int a, int b);
void summary_graph(p_graph g);

#endif



#ifndef STACK_H
#define STACK_H

typedef struct snode {
    int value;
    struct snode *next;
} SNode;

typedef SNode *p_snode;

p_snode create_snode(int value, p_snode next);

void delete_snode(p_snode node);


typedef struct stack {
    p_snode head;
} Stack;

typedef Stack * p_stack;

p_stack create_stack();

void delete_stack(p_stack stack);

int top(p_stack stack);
int empty(p_stack stack)

void pop(p_stack stack);

void push(p_stack stack, int value);

void print_stack(p_stack stack);

#endif
