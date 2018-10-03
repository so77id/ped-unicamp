#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pila.h"


p_snode create_snode(char *value, p_snode next) {
    p_snode aux = malloc(sizeof(SNode));
    aux->value = malloc(sizeof(char) * 30);

    strcpy(aux->value,value)    ;
    aux->next = next;

    return aux;
}

void delete_snode(p_snode node){
    free(node->value);
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

char *top(p_stack stack) {
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

void push(p_stack stack, char *value) {
    stack->head = create_snode(value, stack->head);
}

void print_stack(p_stack stack) {
    p_snode aux = stack->head;
    printf("Print stack:\n");
    while(aux) {
        printf("%s-", aux->value);
        aux = aux->next;
    }
    printf("\n");
}
