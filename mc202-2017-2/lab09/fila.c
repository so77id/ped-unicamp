#include <stdlib.h>

#include "fila.h"
#include "jogador.h"

p_qnode create_qnode(p_player player, p_qnode next) {
    p_qnode qnode = malloc(sizeof(QNode));
    qnode->player = player;
    qnode->next = next;

    return qnode;
}

void delete_qnode(p_qnode node) {
    free(node);
}


p_queue create_queue() {
    p_queue queue = malloc(sizeof(Queue));
    queue->head = queue->tail = NULL;

    return queue;
}

void delete_queue(p_queue queue) {
    p_qnode aux, aux_d;

    aux = queue->head;
    while(!aux) {
        aux_d = aux;
        aux = aux->next;
        delete_qnode(aux_d);
    }
    free(queue);
}

void enqueue(p_queue queue, p_player player) {
    p_qnode aux = create_qnode(player, queue->tail);
    if (queue->head == NULL && queue->tail == queue->head) {
        queue->head = queue->tail = aux;
    } else {
        queue->tail->next = aux;
        queue->tail = aux;
    }
}

p_player dequeue(p_queue queue) {
    p_qnode aux;
    p_player player;

    if (!queue->head) {
        return NULL;
    }

    aux = queue->head;
    queue->head = queue->head->next;

    player = aux->player;
    delete_qnode(aux);

    return player;
}
