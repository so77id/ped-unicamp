#ifndef STACK_H
#define STACK_H

typedef struct snode {
    char *value;
    struct snode *next;
} SNode;

typedef SNode *p_snode;

p_snode create_snode(char *value, p_snode next);

void delete_snode(p_snode node);


typedef struct stack {
    p_snode head;
} Stack;

typedef Stack * p_stack;

p_stack create_stack();

void delete_stack(p_stack stack);

char *top(p_stack stack);

void pop(p_stack stack);

void push(p_stack stack, char *value);

void print_stack(p_stack stack);

#endif
