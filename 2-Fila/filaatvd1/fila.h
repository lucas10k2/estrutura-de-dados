#define VERDADEIRO 1
#define FALSO 0
#define TAM 3

typedef int elemento;

typedef struct tipo_fila {
    elemento vet[TAM];
    int inicio, fim;
} fila;
//Cria fila
void CriarFila(fila *f) {
    (*f).inicio = -1;
    (*f).fim = -1;
}
//Verifica se a fila está vazia.
int FilaVazia(fila *f) {
    return ((*f).inicio == -1);
}
//Verifica se a fila está cheia.
int FilaCheia(fila *f) {
    return (((*f).fim + 1) % TAM == (*f).inicio);
}
//Insere um elemento na fila.
int Enfileirar(fila *f, elemento e) {
    if (FilaCheia(f)) {
        return 0; // indica que a fila está cheia
    }
    if (FilaVazia(f)) {
        (*f).inicio = 0;
    }
    (*f).fim = ((*f).fim + 1) % TAM; // circularidade da fila
    (*f).vet[(*f).fim] = e;
    return 1;
}
//Retira um elemento na fila.
elemento Desenfileirar(fila *f) {
    elemento temp = (*f).vet[(*f).inicio];
    if ((*f).inicio == (*f).fim) {
        (*f).inicio = -1;
        (*f).fim = -1;
    } else {
        (*f).inicio = ((*f).inicio + 1) % TAM; // circularidade da fila
    }
    return temp;
}
//Imprimi a fila
void ImprimeFila(fila *f) {
    if (FilaVazia(f)) {
        printf("Fila vazia.\n");
    } else {
        printf("Conteudo da fila: ");
        int i = (*f).inicio;
        while (i != (*f).fim) {
            printf("%d ", (*f).vet[i]);
            i = (i + 1) % TAM;
        }
        printf("%d\n", (*f).vet[i]);
    }
}
