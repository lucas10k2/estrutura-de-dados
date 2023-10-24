#ifndef PILHA_H
#define PILHA_H

#define VERDADEIRO 1
#define FALSO 0
#define TAM 3

typedef int elemento;

struct tipo_pilha {
    elemento vet[TAM];
    int topo;
};

typedef struct tipo_pilha pilha;

// Cria pilha.
void CriarPilha(pilha *p);

// Verifica se a pilha está vazia.
int PilhaVazia(pilha *p);

// Verifica se a pilha está cheia.
int PilhaCheia(pilha *p);

// Insere um elemento na pilha.
void Empilhar(pilha *p, elemento e);

// Retira um elemento na pilha.
elemento Desempilhar(pilha *p);

#endif
