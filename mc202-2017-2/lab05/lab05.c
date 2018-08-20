#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_NAME 30
#define PERSON_LIST_INIT_CAPACITY 4

typedef struct {
    char name[MAX_SIZE_NAME];
    int phone;
} person;

person * init_person(char *name, int phone) {
    person *p;
    p = (person *)malloc(sizeof(p));
    strcpy(p->name, name);
    p->phone = phone;

    return p;
}

void print_person(person *p) {
    printf("%s %d\n", p->name, p->phone);
}

int delete_person(person *p) {
    free(p);
    return 0;
}


typedef struct {
    person **list;
    int capacity;
    int quantity;
} person_list;


person_list * init_person_list() {
    person_list *pl;
    pl = malloc(sizeof(person_list));

    pl->capacity = PERSON_LIST_INIT_CAPACITY;
    pl->quantity = 0;

    pl->list = (person **)malloc(pl->capacity * sizeof(person *));

    return pl;
}

void duplicate_capacity(person_list *pl) {
    int i;

    person **p_aux;

    pl->capacity *=2;

    p_aux = (person **)malloc(pl->capacity * sizeof(person *));

    for (i = 0; i < pl-> quantity; i++)
        p_aux[i] = pl->list[i];

    free(pl->list);
    pl->list = p_aux;
}

void add_person_to_list(person_list *pl, person *p) {
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
    int i;

    for (i = 0; i < pl-> quantity; i++) {
        delete_person(pl->list[i]);
    }
    free(pl->list);
    free(pl);
    return 0;
}

int main(int argc, char const *argv[]) {
    int phone;
    char name[MAX_SIZE_NAME];
    person *p;
    person_list *pl;

    pl = init_person_list();

    scanf("%s %d", name, &phone);
    while(strcmp(name,"fim") != 0) {
        p = init_person(name, phone);
        add_person_to_list(pl, p);

        scanf("%s %d", name, &phone);
    }

    print_person_list(pl);
    delete_person_list(pl);

    return 0;
}
