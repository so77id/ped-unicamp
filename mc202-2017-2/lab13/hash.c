#include "hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



p_author create_author(char * name) {
    p_author a = malloc(sizeof(Author));
    strcpy(a->name, name);
    a->n_coauthors = 0;

    return a;
}

int add_coauthor(p_author author, p_author coauthor) {
   if(author->n_coauthors < MAX_AUTHORS) {
     author->coauthors[author->n_coauthors++] = coauthor;
   } else {
     printf("Number of coauthors exceded\n");
     exit(EXIT_FAILURE);
   }

   return 1;
}


int find_coauthor(p_author a, char * name){
    int i;
    for (i = 0; i < a->n_coauthors; i++) {
        if(!strcmp(a->coauthors[i]->name, name)) return 1;
    }
    return 0;
}

void delete_author(p_author a) {
    free(a);
}





p_hash create_hash() {
   int i;
   p_hash h = malloc(sizeof(Hash));

   for (i = 0; i < MAX_HASH_SIZE; i++) {
      h->authors[i] = 0;
   }

   return h;
}

int hash1(char *key)
{
   int i, k = 0, n = strlen(key);

   for (i = 0; i < n; ++i) {
      k = (127 * k + key[i]) % MAX_HASH_SIZE;
   }

   return k;
}

int hash2(char *key)
{
   int i, k = 0, n = strlen(key);

   for (i = 0; i < n; ++i) {
      k = (61 * k + (key[i]-'A')) % MAX_HASH_SIZE;
   }

   return k;
}

int insert(p_hash h, char * key, p_author author)
{
   int i = hash1(key);
   int k = hash2(key);

   int cont = 0;

   while(h->authors[i]) {
      if(!strcmp(h->authors[i]->name, key)) return -1;

      if(++cont == MAX_HASH_SIZE) return -2;

      i = (i + k) % MAX_HASH_SIZE;
   }

   h->authors[i] = author;

   return i;
}

int find(p_hash h, char * key)
{
   int i = hash1(key);
   int k = hash2(key);

   int cont = 0;

   while(h->authors[i]) {
      if(!strcmp(h->authors[i]->name, key)) return i;

      if(++cont == MAX_HASH_SIZE) return -2;

      i = (i + k) % MAX_HASH_SIZE;
   }

   return -1;
}

void delete_hash(p_hash h) {
   int i;
   for (i = 0; i < MAX_HASH_SIZE; i++) {
      if(h->authors[i]) free(h->authors[i]);
   }
   free(h);
}
