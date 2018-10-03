#include "jogador.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct qnode {
    p_player player;
    struct qnode *next;
} QNode;

typedef QNode *p_qnode;

p_qnode create_qnode(p_player player, p_qnode next);

void delete_qnode(p_qnode node);

typedef struct queue {
    p_qnode head;
    p_qnode tail;
} Queue;

typedef Queue *p_queue;

p_queue create_queue();

void delete_queue(p_queue queue);

void enqueue(p_queue queue, p_player player);

p_player dequeue(p_queue queue);

#endif
