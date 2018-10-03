#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INT_DIGITS 11


typedef struct node {
    char op;
    int value;
    char var;
    struct node *left, *right;
} Node;

typedef Node *p_node;

p_node create_leaf_value(int value){
    p_node new = malloc(sizeof(Node));
    new->value = value;
    new->var = ' ';
    new->op = ' ';
    new->left = new->right = NULL;

    return new;
}

p_node create_leaf_var(char var){
    p_node new = malloc(sizeof(Node));
    new->value = 0;
    new->var = var;
    new->op = ' ';
    new->left = new->right = NULL;

    return new;
}

p_node create_non_lead_op(char op, p_node left, p_node right){
    p_node new = malloc(sizeof(Node));
    new->value = 0;
    new->var = ' ';
    new->op = op;
    new->left = left;
    new->right = right;

    return new;
}

int is_leaf(p_node n) {
    return n->op == ' ' ? 1 : 0;
}

void delete_node(p_node n){
    if(is_leaf(n)){
        free(n);
    }
    else{
        delete_node(n->left);
        delete_node(n->right);
        free(n);
    }
}


typedef struct tree {
    p_node root;
} Tree;

typedef Tree * p_tree;

p_tree create_tree(){
    p_tree new = malloc(sizeof(Tree));
    new->root = NULL;
    return new;
}

void delete_tree(p_tree t){
    delete_node(t->root);
}


p_node compile_tree(){
    char buff[MAX_INT_DIGITS];
    char op, var;
    int value;
    p_node left, right;
    scanf("%s", buff);
    if(strcmp(buff, "(") == 0){
        left = compile_tree();
        scanf("%s", buff);
        op = buff[0];
        right = compile_tree();

        /* READ ) */
        scanf("%s", buff);
        return create_non_lead_op(op, left, right);
    } else if((buff[0] >= '0' && buff[0] <= '9') || (buff[0] == '-' && buff[1] >= '0' && buff[1] <= '9')) {
        value = atoi(buff);
        return create_leaf_value(value);
    } else {
        var = buff[0];
        return create_leaf_var(var);
    }
}


void read_tree(p_tree t){
    t->root = compile_tree();
}

void print_in_order(p_node root){
    if(is_leaf(root)){
        if(root->var == ' ') printf("%d ", root->value);
        else printf("%c ", root->var);
    } else {
        printf("( ");
        print_in_order(root->left);
        printf("%c ", root->op);
        print_in_order(root->right);
        printf(") ");
    }
}

void print_in_order_tree(p_tree t){
    print_in_order(t->root);
    printf("\n");
}




int is_reducible(p_node n){
    return (n->op != ' ' || n->var != ' ') ? 0 : 1;
}

int calc_op(int num1, int num2, char op){
    int result;
    switch (op) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    }
    return result;
}

p_node prune(p_node root) {
    int value;
    p_node new;

    if(is_leaf(root)){
        return root;
    }

    root->left = prune(root->left);
    root->right = prune(root->right);

    if(is_reducible(root->left) && is_reducible(root->right)) {
        value = calc_op(root->left->value, root->right->value, root->op);
        new = create_leaf_value(value);
        delete_node(root);
        return new;
    } else return root;
}


void prune_tree(p_tree t) {
    t->root = prune(t->root);
}

int main(int argc, char const *argv[]) {
    p_tree t;
    t = create_tree();
    read_tree(t);
    prune_tree(t);
    print_in_order_tree(t);

    return 0;
}
