#include <stdio.h>
#include <string.h>

#include "acao.h"
#include "portfolio.h"


portfolio criar_portfolio(char *nome, char *sobrenome) {
    portfolio p;
    strcpy(p.nome, nome);
    strcpy(p.sobrenome, sobrenome);
    p.n_acoes = 0;

    return p;
}

portfolio adicionar_acao(portfolio p, acao a){
    p.acoes[p.n_acoes] = a;
    p.n_acoes++;
    return p;
}


void criar_relatorio(portfolio p) {
    int i;

    printf("Relatorio de %s %s\n", p.nome, p.sobrenome);
    for (i = 0; i < p.n_acoes; i++) {
        reportar_acao(p.acoes[i]);
    }
}
