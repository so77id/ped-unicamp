#include <stdio.h>
#include "acao.h"
#include "portfolio.h"


int main(int argc, char const *argv[]) {
    char nome[MAX_SIZE_NAME], sobrenome[MAX_SIZE_NAME], acao_nome[MAX_SIZE_NAME];
    int n_acoes, n_variacoes, i, j;
    float investimento, variacao;
    portfolio p;
    acao a;

    scanf("%s", nome);
    scanf("%s", sobrenome);
    scanf("%d", &n_acoes);

    p = criar_portfolio(nome, sobrenome);

    for (i = 0; i < n_acoes; i++) {
        scanf("%s", acao_nome);
        scanf("%f", &investimento);
        scanf("%d", &n_variacoes);

        a = criar_acao(acao_nome, investimento);
        for (j = 0; j < n_variacoes; j++) {
            scanf("%f", &variacao);
            a = adicionar_variacao(a, variacao);
        }

        p = adicionar_acao(p, a);
    }

    criar_relatorio(p);

    return 0;
}
