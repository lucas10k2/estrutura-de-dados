#include <stdio.h>
#include <stdlib.h>
#define TAM 5
typedef int elemento;
#include "pilha.h"

// funcao principal
int main() {
    int num, resto;
    int bits_excedidos = 0; // Contador para rastrear os bits excedidos
    pilha p;
    CriarPilha(&p); // inicializa a pilha

    printf("\nInforme um numero inteiro: ");
    scanf("%d", &num);

    // conversao do numero para binário
    while (num != 0) {
        resto = num % 2;

        // verifica se a pilha excedeu o tamanho de 5 bits
        if (PilhaCheia(&p)) {
            bits_excedidos++;
        } else {
            Empilhar(&p, resto);
        }
        num /= 2;
    }

    // informa ao usuario se a representacao binaria tem mais de 5 bits
    if (bits_excedidos > 0) {
        printf("\nA representacao binaria possui mais de 5 bits.\n");
        printf("Os bits mais significativos nao serao processados.\n");
    }

    int decimal = 0;
    int posicao = 1; // posicao do bit de peso baixo

    printf("\nCorrespondente em binario: ");

    // apresenta a representacao binaria processada e calcula o equivalente decimal
    while (PilhaVazia(&p) == FALSO) {
        resto = Desempilhar(&p);
        printf("%d", resto);
        decimal = decimal * 2 + resto; // calcula o equivalente em decimal
    }

    printf("\nEquivalente em decimal: %d\n", decimal);
    system("pause");
    return 0;
}
