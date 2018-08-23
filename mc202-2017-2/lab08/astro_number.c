#include <stdio.h>
#include <stdlib.h>

#include "astro_number.h"


p_node create_node(int number, p_node next, p_node prev) {
    p_node node;
    node = malloc(sizeof(Node));
    node->number = number;
    node->next = next;
    node->prev = prev;

    return node;
}

void delete_node(p_node node) {
    free(node);
}

p_astro_number create_astro_number(char *number) {
    int i, num;
    p_node prev, current;
    p_astro_number an;

    an = malloc(sizeof(AstroNumber));

    i = 0;
    if (number[i] == '-') {
        an->sign = -1;
        i++;
    } else {
        an->sign = 1;
    }

    current = create_node(number[i++] - '0', NULL, NULL);
    an->head = an->tail = prev = current;
    an->digits = 1;

    for (; i < MAX_NUMBER_SIZE_IN; i++) {
        if (number[i] == '\0') break;

        /* dica */
        num = number[i] - '0';
        if (num < 0 || num > 9 ) break;
        current = create_node(num, NULL, prev);
        prev->next = current;

        an->tail = prev = current;
        an->digits++;
    }

    delete_left_zeros(an);

    return an;
}

void print_astro_number(p_astro_number astro_number) {
    p_node aux;

    if (astro_number->sign == -1) {
        printf("-");
    }

    for (aux = astro_number->head; aux; aux = aux->next) {
        printf("%d", aux->number);
    }
    printf("\n");
}

void delete_astro_number(p_astro_number astro_number) {
    p_node aux, aux_d;

    aux = astro_number->head;

    while(aux) {
        aux_d = aux;
        delete_node(aux_d);

        aux = aux->next;
    }

    free(astro_number);
}


p_astro_number inverse(p_astro_number a) {

    p_node n_aux, a_aux, prev;
    p_astro_number new;
    new = malloc(sizeof(AstroNumber));
    new->tail = new->head = NULL;
    new->digits = 0;

    a_aux = a->head;
    prev = NULL;
    while(a_aux) {
        n_aux = create_node(a_aux->number, NULL, prev);
        if (prev) {
            prev->next = n_aux;
        }
        new->tail = prev = n_aux;
        a_aux = a_aux->next;

        if(!new->head) {
            new->head = n_aux;
        }
        new->digits++;
    }

    new->sign = a->sign * -1;
    return new;
}

p_astro_number sum(p_astro_number a, p_astro_number b) {
    int a_num, b_num, c_num, rest;
    p_astro_number c, inv_a, inv_b, inv_c;
    p_node na, nb, nc, c_next;

    if (a->sign == -1 && b->sign == 1) {
        inv_a = inverse(a);
        c = subtract(b, inv_a);
        delete_astro_number(inv_a);
        return c;
    } else if(a->sign == 1 && b->sign == -1) {
        inv_b = inverse(b);
        c = subtract(a, inv_b);
        delete_astro_number(inv_b);
        return c;
    } else if(a->sign == -1 && b->sign == -1) {
        inv_a = inverse(a);
        inv_b = inverse(b);
        c = sum(inv_a, inv_b);
        inv_c = inverse(c);
        delete_astro_number(inv_a);
        delete_astro_number(inv_b);
        delete_astro_number(c);

        return inv_c;
    }

    c = malloc(sizeof(AstroNumber));
    c->sign = 1;
    c->digits = 0;
    c->head = c->tail = NULL;

    na = a->tail;
    nb = b->tail;

    rest = 0;
    c_next = NULL;
    while((na || nb)) {
        if(na) {
            a_num = na->number;
            na = na->prev;
        } else {
            a_num = 0;
        }

        if (nb) {
            b_num = nb->number;
            nb = nb->prev;
        } else {
            b_num = 0;
        }

        c_num = rest + a_num + b_num;
        rest = c_num / 10;
        c_num = c_num % 10;

        nc = create_node(c_num, c_next, NULL);

        if (c_next) c_next->prev = nc;

        c_next = nc;

        if (!c->tail) {
            c->tail = nc;
        }
        c->digits++;
    }

    if (rest) {
        nc = create_node(rest, c_next, NULL);
        if (c_next) c_next->prev = nc;

        c_next = nc;
        c->digits++;
    }

    c->head = nc;

    delete_left_zeros(c);

    return c;
}

p_astro_number subtract(p_astro_number a, p_astro_number b) {
    int a_num, b_num, c_num, rest;
    p_astro_number c, inv_a, inv_b, inv_c;
    p_node a_aux, b_aux, c_aux, c_next;

    /* free inverses */
    if (a->sign == 1 && b->sign == -1) {
        inv_b = inverse(b);
        c = sum(a, inv_b);
        delete_astro_number(inv_b);
        return c;
    } else if (a->sign == -1 && b->sign == 1) {
        inv_a = inverse(a);
        c = sum(inv_a, b);
        inv_c = inverse(c);
        delete_astro_number(inv_a);
        delete_astro_number(c);
        return inv_c;
    } else if (a->sign == -1 && b-> sign == -1) {
        inv_a = inverse(a);
        inv_b = inverse(b);
        c = subtract(inv_b, inv_a);
        delete_astro_number(inv_a);
        delete_astro_number(inv_b);
        return c;
    }

    if (cmp(a,b) == -1) {
        return inverse(subtract(b, a));
    }

    c = malloc(sizeof(AstroNumber));
    c->head = c->tail = NULL;
    c->sign = 1;
    c->digits = 0;
    a_aux = a->tail;
    b_aux = b->tail;

    rest = 0;
    c_next = NULL;
    while(a_aux || b_aux) {
        if(a_aux) {
            a_num = a_aux->number;
            a_aux = a_aux->prev;
        } else {
            a_num = 0;
        }

        if (b_aux) {
            b_num = b_aux->number;
            b_aux = b_aux->prev;
        } else {
            b_num = 0;
        }
        b_num += rest;
        rest = 0;

        if (b_num > a_num) {
            a_num += 10;
            rest = 1;
        }
        c_num = a_num - b_num;
        c_aux = create_node(c_num, c_next, NULL);

        if (c_next) c_next->prev = c_aux;

        c_next = c_aux;
        c->head = c_aux;

        if (!c->tail) {
            c->tail = c_aux;
        }
        c->digits++;
    }


    delete_left_zeros(c);

    return c;
}


int cmp(p_astro_number a, p_astro_number b) {
    p_node a_aux, b_aux;
    if(a->sign != b->sign) return a->sign;

    if (a->digits > b->digits ) return a->sign;


    if (a->digits < b->digits) return (a->sign * -1);

    a_aux = a->head;
    b_aux = b->head;

    while(b_aux && a_aux) {
        if (a_aux->number > b_aux->number) return a->sign;
        else if(a_aux->number < b_aux->number) return (a->sign * -1);

        a_aux = a_aux->next;
        b_aux = b_aux->next;
    }

    return 0;
}


void delete_left_zeros(p_astro_number a) {
    p_node aux, ptr;

    aux = a->head;

    while(aux && aux->next) {
        if(aux->number != 0) break;
        ptr = aux;
        aux = aux->next;
        aux->prev = NULL;
        delete_node(ptr);
        a->digits--;
    }
    a->head = aux;
}
