
#ifndef TREAP_H
#define TREAP_H

typedef struct node {
    struct node *left;
    struct node *right;
    struct node *prev;
    int value;
    int priority;
} Node;

typedef Node * p_node;

p_node create_node(int value, p_node prev, p_node left, p_node right);
void delete_node(p_node n);


typedef struct treap {
    p_node root;
} Treap;

typedef Treap * p_treap;

p_treap create_treap();
void delete_treap(p_treap t);
void delete_treap_n(p_node n);

void insert(p_treap t, int value);
void left_rotation(p_node n);
void right_rotation(p_node n);
int search(p_treap t, int value);

void print_orders(p_treap t);
void inorder(p_treap t);
void preorder(p_treap t);
void postorder(p_treap t);
void inorder_n(p_node root);
void preorder_n(p_node root);
void postorder_n(p_node root);

p_treap simetric_diff(p_treap *treaps, int n_treaps);
void simetric_diff_n(p_node root, p_treap treap, p_treap sd);


#endif
