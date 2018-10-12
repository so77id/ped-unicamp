#include "treap.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int n_lists, number, i, j, size_list;
    p_treap *treaps, final;

    scanf("%d", &n_lists);
    treaps = malloc(n_lists * sizeof(p_treap));

    for (i = 0; i < n_lists; i++) {
        treaps[i] = create_treap();
    }

    for (i = 0; i < n_lists; i++) {
        scanf("%d", &size_list);
        for (j = 0; j < size_list; j++) {
            scanf("%d", &number);
            insert(treaps[i], number);
        }
    }

    final = simetric_diff(treaps, n_lists);

    inorder(final);

    for (i = 0; i < n_lists; i++) {
        delete_treap(treaps[i]);
    }
    delete_treap(final);
    free(treaps);

    return 0;
}
