#ifndef HEAP_H
#define HEAP_H

#define MAX_HASH_SIZE 1000
#define AUTHOR_NAME_SIZE 16
#define MAX_AUTHORS 1000


typedef struct author {
    char name[AUTHOR_NAME_SIZE + 1];
    struct author* coauthors[MAX_AUTHORS];
    int n_coauthors;
} Author;
typedef Author * p_author;

p_author create_author(char *name);
int add_coauthor(p_author author, p_author coauthor) ;
int find_coauthor(p_author a, char * name);
void delete_author(p_author a);

typedef struct hash {
    p_author authors[MAX_HASH_SIZE];
} Hash;

typedef Hash * p_hash;

p_hash create_hash();
int hash1(char * key);
int hash2(char * key);
int insert(p_hash h, char * key, p_author author);
int find(p_hash h, char * key);
void delete_hash(p_hash h);

#endif
