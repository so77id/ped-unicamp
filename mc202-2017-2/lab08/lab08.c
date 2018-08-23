#include <stdio.h>
#include "astro_number.h"

#define MAX_SIZE_OPERATION 2

int main(int argc, char const *argv[]) {
    int i, n_op;
    char NUM_IN[MAX_NUMBER_SIZE_IN], op[MAX_SIZE_OPERATION];
    p_astro_number a, b, c;

    scanf("%s", NUM_IN);
    a = create_astro_number(NUM_IN);

    scanf("%d", &n_op);

    for (i = 0; i < n_op; i++) {
        scanf("%s", op);

        if (op[0] == '+') {
            scanf("%s", NUM_IN);
            b = create_astro_number(NUM_IN);
            c = sum(a, b);
            delete_astro_number(a);
            delete_astro_number(b);
        } else if (op[0] == '-') {
            scanf("%s", NUM_IN);
            b = create_astro_number(NUM_IN);
            c = subtract(a, b);
            delete_astro_number(a);
            delete_astro_number(b);
        }  else if (op[0] == '*') {
            scanf("%s", NUM_IN);
            b = create_astro_number(NUM_IN);
            c = multiply(a, b);
            delete_astro_number(a);
            delete_astro_number(b);
        } else if (op[0] == 'i') {
            c = inverse(a);
            delete_astro_number(a);
        }
        a = c;
        print_astro_number(a);
    }

    delete_astro_number(a);
    return 0;
}
