#include <stdio.h>
#include <stdlib.h>
#include "universidade.h"


int main(int argc, char const *argv[]) {
    int i, j, n_alunos, n_professores, n_disciplinas;
    double salario, nota, nota_max, nota_min, media_notas;

    char nome[MAX_NOME], sobrenome[MAX_NOME], disciplina[MAX_CODIGO];

    p_professor *p_list;
    p_aluno *a_list;

    scanf("%d", &n_professores);

    p_list = (p_professor *)malloc(n_professores * sizeof(p_professor));

    for (i = 0; i < n_professores; i++) {
        scanf("%s %s %lf %s", nome, sobrenome, &salario, disciplina);
        p_list[i] = criarProfessor(nome, sobrenome, salario, disciplina);
    }

    scanf("%d", &n_alunos);

    a_list = (p_aluno *)malloc(n_alunos * sizeof(p_aluno));

    for (i = 0; i < n_alunos; i++) {
        scanf("%s %s %d", nome, sobrenome, &n_disciplinas);
        a_list[i] = criarAluno(nome, sobrenome);
        for (j = 0; j < n_disciplinas; j++) {
            scanf("%s %lf", disciplina, &nota);
            adicionarDisciplina(a_list[i], disciplina, nota);
        }
    }

    for (i = 0; i < n_professores; i++) {
        obterNotasExtremas(a_list, n_alunos, p_list[i]->disciplina, &nota_min, &nota_max);
        media_notas = (nota_max + nota_min)/2.0;
        reajusteSalario(p_list[i], media_notas);
        imprimirProfessor(p_list[i]);
        destruirProfessor(p_list[i]);
    }

    for (i = 0; i < n_alunos; i++) {
        destruirAluno(a_list[i]);
    }

    return 0;
}
