#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 2


typedef struct {
    char CPF[12];
    char nome[50];
    char endereco[100];
    char telefone[15];
    char celular[15];
    char dataNascimento[11];
    char dataAdmissao[11];
    char departamento[50];
    char cargo[50];
    float salario;
} Funcionario;

typedef struct nodo {
    Funcionario *info; // ponteiro para um objeto funcionario
    struct nodo *prox;// ponteiro para o proximo no na fila
} no; // define a estrutura para cada no da fila, onde cada no contem um ponteiro para um funcionario e um ponteiro para o proximo no

typedef struct {
    no *inicio; // ponteiro para o primeiro no da fila
    no *fim; // ponteiro para o ultimo no da fila
} fila; // define a estrutura da fila, que contem ponteiros para o inicio e o fim da fila

// funcao para criar uma fila vazia
void CriarFila(fila *f) {
    (*f).inicio = 0;
    (*f).fim = 0;
}
// funcao para verificar se a fila esta vazia
int FilaVazia(fila *f) {
    return (*f).inicio == 0;
}
// funcao para enfileirar um elemento na fila
void Enfileirar(fila *f, Funcionario *func) {
    no *novo = (no *)malloc(sizeof(no));
    novo->info = func;
    novo->prox = 0;

    if (FilaVazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

Funcionario *Desenfileirar(fila *f) {
    if (FilaVazia(f)) {
        printf("Fila vazia.\n");
        return 0;
    }

    no *aux = f->inicio;
    Funcionario *func = aux->info;
    f->inicio = f->inicio->prox;

    free(aux);
    return func;
}

#endif
