#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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


p_astro_number multiply(p_astro_number a, p_astro_number b) {
    int i;
    p_astro_number c, aux, sum_, inv_a, inv_b, inv_c, aux_;
    p_node b_ptr;

    if (a->sign == 1 && b->sign == -1) {
        inv_b = inverse(b);
        c = multiply(a, inv_b);
        inv_c = inverse(c);

        delete_astro_number(inv_b);
        delete_astro_number(c);

        return inv_c;
    } else if (a->sign == -1 && b->sign == 1) {
        inv_a = inverse(a);
        c = multiply(inv_a, b);
        inv_c = inverse(c);

        delete_astro_number(inv_a);
        delete_astro_number(c);

        return inv_c;
    } else if (a->sign == -1 && b->sign == -1) {
        inv_a = inverse(a);
        inv_b = inverse(b);
        c = multiply(inv_a, inv_b);

        delete_astro_number(inv_a);
        delete_astro_number(inv_b);

        return c;
    }

    c = create_astro_number("0");

    i = 0;
    for (b_ptr = b->tail; b_ptr; b_ptr = b_ptr->prev) {

        aux = multiply_by_digit(a, b_ptr->number);
        aux_ = add_zeros_in_tail(aux, i);
        sum_ = sum(c, aux_);

        printf("-------------\n");
        printf("Multiplicando\n");
        print_astro_number(a);
        printf("* %d\n", b_ptr->number);
        printf("result: ");
        print_astro_number(aux);
        printf("potenciado: ");
        print_astro_number(aux_);
        printf("Estado anterior de c: ");
        print_astro_number(c);

        delete_astro_number(c);
        delete_astro_number(aux);
        delete_astro_number(aux_);


        c = sum_;
        i++;


        printf("Estado actual de c: ");
        print_astro_number(c);
        printf("\n");



    }

    return c;
}

p_astro_number add_zeros_in_tail(p_astro_number a, int n_zeros) {
    int i;
    p_node new;
    if (a->head == a->tail && a->head == NULL) return a;

    for (i = 0; i < n_zeros; i++) {
        new = create_node(0, NULL, a->tail);
        a->tail->next = new;
        a->tail = new;
        a->digits++;
    }

    return a;
}


p_astro_number multiply_by_digit(p_astro_number a, int digit) {
    int rest, aux_nun;
    p_astro_number aux;
    p_node a_ptr, c_next, nc;

    aux = malloc(sizeof(AstroNumber));
    if((digit >= 0 && a->sign > 0) || (digit <= 0 && a->sign < 0)) {
        aux->sign = 1;
    } else {
        aux->sign = 0;
    }
    aux->digits = 0;
    aux->head = aux->tail = NULL;

    rest = 0;
    c_next = NULL;
    for (a_ptr = a->tail; a_ptr; a_ptr = a_ptr->prev) {

        aux_nun = rest + (a_ptr->number * digit);
        rest = aux_nun / 10;
        aux_nun = aux_nun % 10;

        nc = create_node(aux_nun, c_next, NULL);

        if (c_next) c_next->prev = nc;

        c_next = nc;

        if (!aux->tail) {
            aux->tail = nc;
        }
        aux->digits++;
    }

    if (rest) {
        nc = create_node(rest, c_next, NULL);
        if (c_next) c_next->prev = nc;

        c_next = nc;
        aux->digits++;
    }

    aux->head = nc;

    delete_left_zeros(aux);

    return aux;


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
