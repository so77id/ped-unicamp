#include "treap.h"

#include <stdlib.h>
#include <stdio.h>

p_node create_node(int value, p_node prev, p_node left, p_node right){
    p_node new = malloc(sizeof(Node));
    new->left = left;
    new->right = right;
    new->prev = prev;
    new->value = value;
    new->priority = rand() % 100;

    return new;
}

void delete_node(p_node n) {
    free(n);
}

p_treap create_treap() {
    p_treap t = malloc(sizeof(Treap));
    t->root = NULL;
    return t;
}

void delete_treap(p_treap t) {
    if (!t->root) return;
    delete_treap_n(t->root);
    free(t);
}

void delete_treap_n(p_node n) {
    if(!n) return;
    delete_treap_n(n->left);
    delete_treap_n(n->right);
    delete_node(n);
}

void insert(p_treap t, int value) {
    p_node aux;

    if(!t->root) {
        t->root = create_node(value, NULL, NULL, NULL);
        return;
    }

    aux = t->root;
    while(1) {
        if(aux->value > value) {
            if (aux->left) aux = aux->left;
            else {
                aux->left = create_node(value, aux, NULL, NULL);
                aux = aux->left;
                break;
            }
        } else {
            if (aux->right) aux = aux->right;
            else {
                aux->right = create_node(value, aux, NULL, NULL);
                aux = aux->right;
                break;
            }
        }
    }

    while(aux) {
        if(!aux->prev) break;
        if (aux->priority <= aux->prev->priority) break;
        if(aux == aux->prev->left) {
            if(aux->prev == t->root) t->root = aux;
            right_rotation(aux);
        } else {
            if(aux->prev == t->root) t->root = aux;
            left_rotation(aux);
        }
    }

}


void left_rotation(p_node n) {
    p_node prev, prev_prev;
    prev = n->prev;
    prev_prev = n->prev->prev;

    if(prev_prev) {
        if(prev_prev->left == prev) {
            prev_prev->left = n;
        } else if(prev_prev->right == prev) {
            prev_prev->right = n;
        }
    }
    n->prev = prev_prev;

    prev->prev = n;
    prev->right = n->left;
    if(n->left) n->left->prev = prev;

    n->left = prev;
}
void right_rotation(p_node n) {
    p_node prev, prev_prev;
    prev = n->prev;
    prev_prev = n->prev->prev;

    if(prev_prev) {
        if(prev_prev->left == prev) {
            prev_prev->left = n;
        } else if(prev_prev->right == prev) {
            prev_prev->right = n;
        }
    }
    n->prev = prev_prev;

    prev->prev = n;
    prev->left = n->right;
    if(n->right) n->right->prev = prev;

    n->right = prev;
}

int search(p_treap t, int value) {
    p_node aux = t->root;

    while(aux) {
        if (aux->value == value) return 1;
        else if (aux->value > value) aux = aux->left;
        else aux = aux->right;
    }

    return 0;
}

void print_orders(p_treap t) {
    printf("inorder: "); inorder(t);
    printf("preorder: "); preorder(t);
    printf("postorder: "); postorder(t);
    printf("\n");
}

void inorder(p_treap t) {
    if(t->root) {
        inorder_n(t->root);
        printf("\n");
    }
}
void preorder(p_treap t) {
    if(t->root) {
        preorder_n(t->root);
        printf("\n");
    }
}
void postorder(p_treap t) {
    if(t->root) {
        postorder_n(t->root);
        printf("\n");
    }
}

void inorder_n(p_node root) {
    if(root) {
        inorder_n(root->right);
        printf("%d ", root->value);
        inorder_n(root->left);
    }
}

void preorder_n(p_node root) {
    if(root) {
        printf("(%d, %d) ", root->value, root->priority);
        preorder_n(root->left);
        preorder_n(root->right);
    }
}

void postorder_n(p_node root) {
    if(root) {
        postorder_n(root->left);
        postorder_n(root->right);
        printf("(%d, %d) ", root->value, root->priority);
    }
}

p_treap simetric_diff(p_treap *treaps, int n_treaps)  {
    int i;
    p_treap sd, aux;

    aux = treaps[0];

    for (i = 1; i < n_treaps; i++) {
        sd = create_treap();
        simetric_diff_n(aux->root, treaps[i], sd);
        simetric_diff_n(treaps[i]->root, aux, sd);

        if(i>1) delete_treap(aux);
        aux = sd;
    }

    return sd;
}

void simetric_diff_n(p_node root, p_treap treap, p_treap sd) {
    if(!root) return;
    simetric_diff_n(root->left, treap, sd);
    simetric_diff_n(root->right, treap, sd);

    if(!search(treap, root->value)) insert(sd, root->value);
}
