#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(p_product a, p_product b) {
    return a->weight - b->weight;
}


int max(p_product a, p_product b) {
    return b->weight - a->weight;
}

int main(int argc, char const *argv[]) {
    char product_name[MAX_NAME];
    float weight, med = 0.0;
    int max_size, min_size;
    p_product p;
    p_heap max_heap, min_heap;

    max_heap = create_heap(max);
    min_heap = create_heap(min);

    scanf("%s", product_name);
    while(strcmp(product_name, "#")) {
        scanf("%f", &weight);
        p = create_product(product_name, weight);

        if(med > weight) {
            enqueue(max_heap, p);
        } else {
            enqueue(min_heap, p);
        }

        max_size = n_items(max_heap);
        min_size = n_items(min_heap);

        if(abs(max_size - min_size) > 1) {
            if(max_size > min_size) {
                p = top(max_heap);
                dequeue(max_heap);
                enqueue(min_heap, p);
                max_size--;
                min_size++;
            } else {
                p = top(min_heap);
                dequeue(min_heap);
                enqueue(max_heap, p);
                min_size--;
                max_size++;
            }
        }

        if(max_size > min_size) {
            med = top(max_heap)->weight;
            print_product(top(max_heap));
        } else if (max_size < min_size) {
            med = top(min_heap)->weight;
            print_product(top(min_heap));
        } else {
            med = (top(max_heap)->weight + top(min_heap)->weight)/2.0;
            print_product(top(max_heap));
            print_product(top(min_heap));
        }

        scanf("%s", product_name);
    }
    
    delete_heap(max_heap);
    delete_heap(min_heap);


    return 0;
}
