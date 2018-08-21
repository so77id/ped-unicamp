#include <stdlib.h>
#include <stdio.h>
#include "universidade.h"
#include "string.h"

p_professor criarProfessor(char nome[], char sobrenome[], double salario, char disciplina[]) {
    p_professor p;
    p = (p_professor)malloc(sizeof(Professor));
    strcpy(p->nome, nome);
    strcpy(p->sobrenome, sobrenome);
    p->salario = salario;
    strcpy(p->disciplina, disciplina);

    return p;
}


void destruirProfessor(p_professor professor) {
    free(professor);
}

p_aluno criarAluno(char nome[], char sobrenome[]) {
    p_aluno a;
    a = (p_aluno)malloc(sizeof(Aluno));
    strcpy(a->nome, nome);
    strcpy(a->sobrenome, sobrenome);
    a->qtd_disciplinas = 0;

    return a;
}


void adicionarDisciplina(p_aluno aluno, char disciplina[], double nota) {
    strcpy(aluno->disciplinas[aluno->qtd_disciplinas], disciplina);
    aluno->notas[aluno->qtd_disciplinas] = nota;
    aluno->qtd_disciplinas++;
}

void destruirAluno(p_aluno aluno) {
    free(aluno);
}


void obterNotasExtremas(p_aluno alunos[], int qtd_alunos, char disciplina[], double *nota_min, double *nota_max) {
    int i, j;
    double min, max;
    min = 11.0;
    max = -1.0;
    for (i = 0; i < qtd_alunos; i++) {
        for (j = 0; j < alunos[i]->qtd_disciplinas; j++) {
            if (strcmp(disciplina, alunos[i]->disciplinas[j]) == 0 ) {
                if(alunos[i]->notas[j] < min) {
                    min = alunos[i]->notas[j];
                }
                if(alunos[i]->notas[j] > max) {
                    max = alunos[i]->notas[j];
                }
                break;
            }
        }
    }
    *nota_min = min;
    *nota_max = max;
}

void reajusteSalario(p_professor professor, double media_notas) {
    double aumento;
    if (media_notas == 10.0) {
        aumento = 15;
    } else if (media_notas >= 9.0) {
        aumento = 10;
    } else if (media_notas >= 8.5) {
        aumento = 5;
    } else {
        aumento = 0;
    }
    professor->salario += professor->salario * aumento/100;
}

void imprimirProfessor(p_professor professor) {
    printf("%s %s %.2f\n", professor->nome, professor->sobrenome, professor->salario);
}
