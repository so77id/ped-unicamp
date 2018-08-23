#ifndef ASTRO_NUMBER_H
#define ASTRO_NUMBER_H


#define MAX_NUMBER_SIZE_IN 10000


typedef struct node {
    int number;
    struct node * next;
    struct node * prev;
} Node;
typedef Node * p_node;

p_node create_node(int number, p_node next, p_node prev);

void delete_node(p_node node);

typedef struct {
    int sign;
    int digits;
    p_node head;
    p_node tail;
} AstroNumber;

typedef AstroNumber * p_astro_number;

p_astro_number create_astro_number(char *number);

void delete_astro_number(p_astro_number astro_number);

p_astro_number inverse(p_astro_number a);
p_astro_number sum(p_astro_number a, p_astro_number b);
p_astro_number subtract(p_astro_number a, p_astro_number b);
p_astro_number multiply(p_astro_number a, p_astro_number b);
p_astro_number division(p_astro_number a, p_astro_number b);

int cmp(p_astro_number a, p_astro_number b);
void print_astro_number(p_astro_number astro_number);
void delete_left_zeros(p_astro_number a);

#endif
