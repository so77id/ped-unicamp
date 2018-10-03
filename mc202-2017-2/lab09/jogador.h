#ifndef PLAYER_H
#define PLAYER_H

#define MAX_CARDS 52

typedef struct player {
    int cards[MAX_CARDS];
    int n_cards;
} Player;
typedef Player *p_player;

p_player create_player();

void delete_player(p_player player);

void insert_card(p_player player, char *card);

void delete_card(p_player player, char *card);

int calculate_score(p_player player);


#endif
