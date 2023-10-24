/*
* Arquivo: pilha.h
* Biblicoteca de opera��es para pilha
* implementada com vetor.
*/
#define VERDADEIRO 1
#define FALSO 0
struct tipo_pilha {
elemento vet[TAM];
int topo;
};
typedef struct tipo_pilha pilha;
//Cria pilha.
void CriarPilha(pilha *p) {
(*p).topo = 0;
}
//Verifica se a pilha est� vazia.
int PilhaVazia(pilha *p) {
return((*p).topo == 0);
}
//Verifica se a pilha est� cheia.
int PilhaCheia(pilha *p) {
return((*p).topo == TAM);
}
//Insere um elemento na pilha.
void Empilhar(pilha *p, elemento e) {
(*p).vet[(*p).topo] = e;
(*p).topo++;
}
//Retira um elemento na pilha.
elemento Desempilhar(pilha *p) {
(*p).topo--;
return (*p).vet[(*p).topo];
}

// Imprime o conte�do da pilha.
void ImprimePilha(pilha *p) {
    if (PilhaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Conteudo da pilha:\n");
    for (int i = 0; i <= (*p).topo; i++) {
        printf("%d ", (*p).vet[i]);
    }
    printf("\n");
}
