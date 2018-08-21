#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_NAME 30
#define PERSON_LIST_INIT_CAPACITY 4

typedef struct {
    char name[MAX_SIZE_NAME];
    int phone;
} person;

person init_person(char *name, int phone) {
    person p;
    strcpy(p.name, name);
    p.phone = phone;

    return p;
}

void print_person(person p) {
    printf("%s %d", p.name, p.phone);
}


typedef struct {
    person *list;
    int capacity;
    int quantity;
} person_list;


person_list *init_person_list() {
    person_list *pl;
    pl = malloc(sizeof(person_list));

    pl->capacity = PERSON_LIST_INIT_CAPACITY;
    pl->quantity = 0;

    pl->list = (person *)malloc(pl->capacity * sizeof(person));

    return pl;
}

void duplicate_capacity(person_list *pl) {
    int i;

    person *p_aux;

    pl->capacity *=2;

    p_aux = (person *)malloc(pl->capacity * sizeof(person));

    for (i = 0; i < pl-> quantity; i++)
        p_aux[i] = pl->list[i];

    free(pl->list);
    pl->list = p_aux;
}

void add_person_to_list(person_list *pl, person p) {
    if (pl->quantity +1 >= pl->capacity) {
        duplicate_capacity(pl);
    }
    pl->list[pl->quantity++] = p;
}


void print_person_list(person_list *pl) {
    int i;
    for (i = 0; i < pl->quantity; i++) {
        print_person(pl->list[i]);
    }
}


int delete_person_list(person_list *pl) {
    free(pl->list);
    free(pl);
    return 0;
}


int comp (const void * elem1, const void * elem2)
{
    person f = *((person *)elem1);
    person s = *((person *)elem2);
    if (f.phone > s.phone) return  1;
    if (f.phone < s.phone) return -1;
    return 0;
}

int main(int argc, char const *argv[]) {
    char name[MAX_SIZE_NAME];
    int phone;
    person p;
    person_list *pl;

    pl = init_person_list();

    scanf("%s", name);
    while(strcmp(name,"fim") != 0) {
        scanf("%d", &phone);

        p = init_person(name, phone);
        add_person_to_list(pl, p);

        scanf("%s", name);
    }

    scanf("%d", &phone);
    qsort (pl->list, pl->quantity, sizeof(person), comp);
    print_person(pl->list[phone-1]);

    delete_person_list(pl);

    return 0;
}
