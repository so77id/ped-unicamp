#ifndef HEAP_H
#define HEAP_H

#define MAX_NAME 20
#define HEAP_INITIAL_SIZE 4

typedef struct product {
    char name[MAX_NAME];
    float weight;
} Product;
typedef Product * p_product;

p_product create_product(char *name, float weight);
void delete_product(p_product p);
void print_product(p_product p);

typedef struct heap {
    int (*cmp)();
    p_product *items;
    int n_items;
    int size;
} Heap;
typedef Heap * p_heap;

p_heap create_heap(int (*cmp)());
void delete_heap(p_heap h);
void h_realloc(p_heap h);
int n_items(p_heap h);
void swap(p_heap h, int i, int j);
void print_heap(p_heap h);


void enqueue(p_heap h, p_product p);
p_product top(p_heap h);
void dequeue(p_heap h);

#endif
