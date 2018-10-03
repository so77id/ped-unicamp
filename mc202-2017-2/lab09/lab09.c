#include <stdio.h>
#include <string.h>
#include "pila.h"
#include "fila.h"
#include "jogador.h"

void new_card(p_stack cards, p_player player) {
    char *card = top(cards);
    pop(cards);

    insert_card(player, card);
}


int main(int argc, char const *argv[]) {
    int n_cards, n_players, i, score;
    char card[10], action[10];
    p_stack stack;
    p_queue queue, q_not_stand;
    p_player player, dealer;

    stack = create_stack();
    queue = create_queue();
    q_not_stand = create_queue();


    scanf("%d %d", &n_cards, &n_players);

    for (i = 0; i < n_cards; i++){
        scanf("%s", card);
        printf("Insertando %d, %s\n", i, card);
        push(stack, card);
        print_stack(stack);
    }

    for (i = 0; i < n_players; i++){
        player = create_player();
        enqueue(queue, player);
        enqueue(q_not_stand, player);
    }
    dealer = create_player();
    enqueue(q_not_stand, dealer);
    printf("ENCOLE\n");
    /* first card */
    for(i = 0; i < n_players; i++) {
        player = dequeue(q_not_stand);
        new_card(stack, player);
        enqueue(q_not_stand, player);
    }
    printf("primera carta\n");

    /* second card */
    for(i = 0; i < n_players; i++) {
        player = dequeue(q_not_stand);
        new_card(stack, player);

        score = calculate_score(player);
        if(score < 20)
            enqueue(q_not_stand, player);
    }
    printf("segunda carta\n");


    scanf("%s", action);
    while(strcmp(action, "#") != 0) {

        printf("Accion leida %s\n",  action);
        if (strcmp(action,"H")==0) {
            player = dequeue(q_not_stand);

            new_card(stack, player);

            score = calculate_score(player);
            if(score < 20)
                enqueue(q_not_stand, player);
        } else if (strcmp(action, "S")==0) {
            player = dequeue(q_not_stand);
        } else {
            delete_card(dealer, action);
            push(stack, action);
        }
        scanf("%s", action);
    }

    player = dequeue(queue);
    while(player) {
        printf("%d\n", calculate_score(player));
        delete_player(player);
    }

    delete_stack(stack);
    delete_queue(queue);
    delete_queue(q_not_stand);

    return 0;
}
