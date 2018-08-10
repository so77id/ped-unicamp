#include <stdio.h>
#include <string.h>
#include "acao.h"


acao criar_acao(char *nome, float investimento) {
    acao a;
    strcpy(a.nome, nome);
    a.investimento = investimento;
    a.n_variacoes = 0;

    return a;
}

acao adicionar_variacao(acao a, float variacao) {
    a.variacoes[a.n_variacoes] = variacao;
    a.n_variacoes++;
    return a;
}

void reportar_acao(acao a) {
    int i;
    char msg[6];

    float valor = a.investimento;
    for (i = 0; i < a.n_variacoes; i++) {
        valor *= (a.variacoes[i] + 100.0) / 100.0;
    }

    if (valor > a.investimento) {
        strcpy(msg, "GANHO");
    } else {
        strcpy(msg, "PERDA");
    }

    printf("%s %.2f %s\n", a.nome, valor, msg);
}
