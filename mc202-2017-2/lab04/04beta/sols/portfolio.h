
#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "acao.h"

#define MAX_ACOES 100

typedef struct {
    char nome[MAX_SIZE_NAME];
    char sobrenome[MAX_SIZE_NAME];
    acao acoes[MAX_ACOES];
    int n_acoes;
} portfolio;

portfolio criar_portfolio(char *nome, char *sobrenome);

portfolio adicionar_acao(portfolio p, acao a);

void criar_relatorio(portfolio p);

#endif
