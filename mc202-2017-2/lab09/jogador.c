#include <stdlib.h>
#include <string.h>

#include "jogador.h"

p_player create_player() {
    p_player player = malloc(sizeof(Player));

    player->n_cards = 0;

    return player;
}

void delete_player(p_player player) {
    free(player);
}

void insert_card(p_player player, char *card) {
    int icard;
    if(strcmp(card,"V") == 0 || strcmp(card, "D") == 0 || strcmp(card, "r") == 0) {
        icard = 10;
    } else if (strcmp(card, "A") == 0){
        icard = 1;
    } else {
        icard = atoi(card);
    }
    player->cards[player->n_cards++] = icard;
}

void delete_card(p_player player, char *card) {
    int i;
    int icard;
    if(strcmp(card,"V") == 0 || strcmp(card, "D") == 0 || strcmp(card, "r") == 0) {
        icard = 10;
    } else if (strcmp(card, "A") == 0){
        icard = 1;
    } else {
        icard = atoi(card);
    }

    for (i = 0; i < player->n_cards; i++) {
        if(player->cards[i] == icard) break;
    }

    for (; i < player->n_cards-1; i++) {
        player->cards[i] = player->cards[i+1];
    }
    player->n_cards--;
}

int calculate_score(p_player player){
    int i, score, n_as;

    n_as = 0;
    for (i = 0; i < player->n_cards; i++) {
        if(player->cards[i] == 1) {
            score += 11;
            n_as++;
        } else {
            score += player->cards[i];
        }
    }

    for (i = 0; i < n_as && score > 21; i++) {
        score -= 10;
    }

    return score;
}
