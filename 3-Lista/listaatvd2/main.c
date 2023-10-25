#include <stdio.h>
#include <stdlib.h>
#define TAM 10
typedef float elemento;
#include "lista.h"

int main() {
    int pos = 0;
    lista l;
    CriarLista(&l);

    printf("Insira 10 numeros reais:\n");
    for (int i = 0; i < 10; i++) {
        float num;
        printf("Informe um numero real: ");
        scanf("%f", &num);
        Enfileirar(&l, num);
    }

    DesenfileirarParaArquivo(&l, "numeros.txt");

    CriarLista(&l);

    EnfileirarDoArquivo(&l, "numeros.txt");

    printf("\nConteudo da lista apos ler do arquivo:\n");
    ImprimeLista(&l);

    printf("\n");
    system("pause");
    return 0;
}
