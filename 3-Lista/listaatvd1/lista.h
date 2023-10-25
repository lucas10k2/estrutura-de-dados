#define TAM 3
typedef int elemento;

typedef struct tipo_lista {
    elemento vet[TAM];
    int inicio, fim;
} lista;

// Cria lista.
void CriarLista(lista *l) {
    (*l).inicio = 0;
    (*l).fim = 0;
}

// Verifica se a lista esta vazia.
int ListaVazia(lista *l) {
    return ((*l).inicio == (*l).fim);
}

// Verifica se a lista esta cheia.
int ListaCheia(lista *l) {
    return ((*l).fim == TAM);
}

// Insere um elemento na lista.
void Inserir(lista *l, elemento e, int pos) {
    int i;
    if (ListaCheia(l))
        printf("\n ERRO: lista cheia!");
    else if ((pos < 0) || (pos > (*l).fim)) {
        printf("\n ERRO: posição não existe!");
        printf("\n Posicoes validas: [0, %d].", (*l).fim);
    } else {
        for (i = (*l).fim; i > pos; i--)
            (*l).vet[i] = (*l).vet[i - 1];
        (*l).vet[pos] = e;
        (*l).fim++;
    }
}

// Retira um elemento da lista.
elemento Retirar(lista *l, int pos) {
    int i;
    elemento e;
    if (ListaVazia(l))
        printf("\n ERRO: lista vazia!");
    else if ((pos < 0) || (pos >= (*l).fim)) {
        printf("\n ERRO: posição não existe!");
        printf("\n Posicoes validas: [0, %d].", (*l).fim - 1);
    } else {
        e = (*l).vet[pos];
        for (i = pos; i < ((*l).fim - 1); i++)
            (*l).vet[i] = (*l).vet[i + 1];
        (*l).fim--;
    }
    return (e);
}

// Imprime o conteúdo da lista.
void ImprimeLista(lista *l) {
    if (ListaVazia(l)) {
        printf("\nLista vazia\n");
    } else {
        printf("\nConteúdo da lista:\n");
        for (int i = (*l).inicio; i < (*l).fim; i++) {
            printf("%d ", (*l).vet[i]);
        }
        printf("\n");
    }
}
