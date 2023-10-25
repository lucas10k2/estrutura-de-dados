#include <stdio.h>
#include <stdlib.h>
#define TAM 3
typedef int elemento;
#include "fila.h"

int main() {
    int num;
    fila f;
    CriarFila(&f);


    while(!FilaCheia(&f)) {
        printf("\nInforme um numero inteiro: ");
        scanf("%d", &num);
        if(!Enfileirar(&f, num)) {
            printf("\nA fila esta cheia. Nao e possivel adicionar mais elementos.\n");
            break;
        }
    }
    printf("\nNumeros informados: ");
    ImprimeFila(&f);
    while(!FilaVazia(&f)) {
        num = Desenfileirar(&f);
        printf("\n%d", num);
    }
    printf("\n");
    system("pause");
    return 0;
}
