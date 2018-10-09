#include "heap.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

p_product create_product(char *name, float weight) {
    p_product p = malloc(sizeof(Product));
    strcpy(p->name, name);
    p->weight = weight;

    return p;
}

void delete_product(p_product p) {
    free(p);
}

void print_product(p_product p) {
    printf("%s: %d\n", p->name, (int)p->weight);
}


p_heap create_heap(int (*cmp)()) {
    p_heap h = malloc(sizeof(Heap));
    h->cmp = cmp;
    h->n_items = 0;
    h->size = 4;
    h->items = malloc(h->size * sizeof(p_product));

    return h;
}

void delete_heap(p_heap h) {
    int i;

    for (i = 1; i <= h->n_items; i++) {
        delete_product(h->items[i]);
    }

    free(h->items);
    free(h);
}

void h_realloc(p_heap h) {
    h->size *= 2;
    h->items = realloc(h->items, h->size * sizeof(p_product));
}

int n_items(p_heap h) {
    return h->n_items;
}

void swap(p_heap h, int i, int j) {
    p_product aux = h->items[i];
    h->items[i] = h->items[j];
    h->items[j] = aux;
}

void print_heap(p_heap h) {
    int i;
    printf("Print heap\n");
    for(i = 1; i <= h->n_items; i++) {
        print_product(h->items[i]);
    }
    printf("------------\n");
}


void enqueue(p_heap h, p_product p) {
    int i;
    if(h->n_items + 1 == h->size) {
        h_realloc(h);
    }

    h->items[++h->n_items] = p;

    i = h->n_items;
    while(i > 1) {
        if(h->cmp(h->items[i], h->items[i/2]) >= 0) break;
        swap(h, i, i/2);
        i /= 2;
    }
}

p_product top(p_heap h) {
    return h->items[1];
}

void dequeue(p_heap h) {
    int i, i_max;

    swap(h, 1, h->n_items--);

    if(!h->n_items) return;

    i = 1;
    while(i <= h->n_items) {
        if((i*2) > h->n_items) break;
        if(( (i*2) + 1 ) > h->n_items) i_max = i*2;
        else if (h->cmp(h->items[i*2], h->items[(i*2) + 1]) > 0 ) {
            i_max = (i*2) + 1;
        } else {
            i_max = i*2;
        }

        if (h->cmp(h->items[i], h->items[i_max]) > 0) {
            swap(h, i, i_max);
            i = i_max;
        } else break;
    }
}
