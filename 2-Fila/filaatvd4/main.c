#include <stdio.h>
#include <stdlib.h>
#include "filacircular.h"

// inicializa a fila circular
void CriarFilaCircular(fila_circular *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

// verifica a fila circular se esta vazia
int FilaCircularVazia(fila_circular *f) {
    return (f->quantidade == 0);
}

// verifica a fila circular esta cheia
int FilaCircularCheia(fila_circular *f) {
    return (f->quantidade == TAM);
}

// adiciona um novo elemento na fila, substituindo o mais antigo se a fila estiver cheia
void EnfileirarCircular(fila_circular *f, char letra, int numero) {
    if (FilaCircularCheia(f)) {
        printf("A letra mais antiga %c foi substituida por %c.\n", f->vet[f->inicio % TAM].letra, letra);
        f->vet[f->inicio % TAM].letra = letra;
        f->vet[f->inicio % TAM].numero = numero;
        f->inicio++;
    } else {
        f->vet[f->fim].letra = letra;
        f->vet[f->fim].numero = numero;
        f->fim++;
        f->quantidade++;
        printf("O elemento %c com numero %d foi enfileirado com sucesso.\n", letra, numero);
    }
}

// remove um elemento da fila
elemento DesenfileirarCircular(fila_circular *f) {
    if (FilaCircularVazia(f)) {
        printf("A fila esta vazia. Nao ha elementos para desenfileirar.\n");
        elemento vazio = {'\0', -1};
        return vazio;
    } else {
        elemento valor = f->vet[f->inicio % TAM];
        f->inicio++;
        f->quantidade--;
        printf("O elemento %c com numero %d foi desenfileirado com sucesso.\n", valor.letra, valor.numero);
        return valor;
    }
}

int main() {
    char letra;
    int numero;
    fila_circular f;
    CriarFilaCircular(&f);

    while (1) {
        if (FilaCircularCheia(&f)) {
            printf("\nA fila esta cheia. Deseja enfileirar mais um elemento? (S/N): ");
            char resposta;
            scanf(" %c", &resposta);
            if (resposta == 'N' || resposta == 'n') {
                break;
            }
        }

        printf("\nInforme uma letra para enfileirar na fila: ");
        scanf(" %c", &letra);

        printf("Informe um numero correspondente: ");
        scanf("%d", &numero);

        if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')) {
            EnfileirarCircular(&f, letra, numero);
        } else {
            printf("Por favor, insira apenas letras de A a Z ou a a z.\n");
        }
    }

    printf("\nFila final: \n");
    for (int i = 0; i < TAM; i++) {
        printf("Letra: %c, Numero: %d\n", f.vet[i].letra, f.vet[i].numero);
    }

    return 0;
}
