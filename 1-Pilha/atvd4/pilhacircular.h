#ifndef PILHACIRCULAR_H
#define PILHACIRCULAR_H

#define TAM 5  // pilha circular

typedef char elemento;

// estrutura da pilha circular
typedef struct {
    elemento vet[TAM];
    int topo;
} pilha_circular;

// cria pilha circular e inicializa o topo como 0
void CriarPilhaCircular(pilha_circular *p);

// verifica se a pilha circular esta vazia
int PilhaCircularVazia(pilha_circular *p);

// verifica se a pilha circular esta cheia
int PilhaCircularCheia(pilha_circular *p);

// insere um elemento na pilha circular e troca o mais antigo se a pilha tiver cheia
void EmpilharCircular(pilha_circular *p, elemento e);

// retira um elemento na pilha circular
elemento DesempilharCircular(pilha_circular *p);

#endif
