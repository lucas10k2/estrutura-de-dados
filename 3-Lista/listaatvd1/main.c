#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    int num, pos = 0;
    lista l;
    CriarLista(&l);

    while (ListaCheia(&l) == 0) {
        printf("\nInforme um numero inteiro: ");
        scanf("%d", &num);
        Inserir(&l, num, pos);
    }

    printf("\nNumeros informados: ");
    while (ListaVazia(&l) == 0) {
        num = Retirar(&l, pos);
        printf("\n%d", num);
    }

    ImprimeLista(&l);

    printf("\n");
    system("pause");
    return 0;
}
