#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(int argc, char const *argv[]) {
    int n_papers, n_querys, n_authors, i, j, k;
    char name[AUTHOR_NAME_SIZE+1], separador;
    p_author authors[MAX_AUTHORS], author;
    p_hash hash;

    n_authors = 0;
    hash = create_hash();

    scanf("%d %d", &n_papers, &n_querys);

    for (i = 0; i < n_papers; i++) {
        n_authors = 0;
        do {
            scanf(" %c. %[^.,]%c", name, name+1, &separador);
            k = find(hash, name);
            if(k < 0) {
                author = create_author(name);
                insert(hash, name, author);
            } else {
                author = hash->authors[k];
            }
            authors[n_authors++] = author;
        } while(separador != '.');

        for (j = 0; j < n_authors; j++) {
            for (k = 1; k < n_authors; k++) {
                add_coauthor(authors[j], authors[k]);
                add_coauthor(authors[k], authors[j]);
            }
        }
    }

    for (i = 0; i < n_querys; i++) {
        scanf(" %c. %[^.,]%c", name, name+1, &separador);
        j = find(hash, name);
        if (j < 0) {
            scanf(" %c. %[^.,]%c", name, name+1, &separador);
            printf("N\n");
        } else {
            author = hash->authors[j];
            scanf(" %c. %[^.,]%c", name, name+1, &separador);
            if(find_coauthor(author, name)) printf("S\n");
            else printf("N\n");
        }
    }

    delete_hash(hash);

    return 0;
}
