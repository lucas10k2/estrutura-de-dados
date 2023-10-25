#include <stdio.h>
#include <stdlib.h>
#include "pilhacircular.h"

// cria uma pilha circular
void CriarPilhaCircular(pilha_circular *p) {
    p->topo = 0;
}

// verifica se a pilha circular esta vazia
int PilhaCircularVazia(pilha_circular *p) {
    return (p->topo == 0);
}

// verifica se a pilha circular esta cheia
int PilhaCircularCheia(pilha_circular *p) {
    return (p->topo == TAM);
}

// insere um novo elemento na pilha circular,trocando o mais antigo
void EmpilharCircular(pilha_circular *p, elemento e) {
    if (PilhaCircularCheia(p)) {
        p->vet[p->topo % TAM] = e;
        p->topo++;
        printf("A pilha esta cheia. O elemento %c foi inserido, substituindo o mais antigo.\n", e);
    } else {
        p->vet[p->topo] = e;
        p->topo++;
        printf("O elemento %c foi inserido com sucesso.\n", e);
    }
}

// retira um elemento da pilha circular
elemento DesempilharCircular(pilha_circular *p) {
    if (PilhaCircularVazia(p)) {
        printf("A pilha esta vazia. Nao ha elementos para retirar.\n");
        return '\0';
    } else {
        p->topo--;
        printf("O elemento %c foi retirado com sucesso.\n", p->vet[p->topo % TAM]);
        return p->vet[p->topo % TAM];
    }
}

// Funcao principal
int main() {
    elemento letra;
    pilha_circular p;
    CriarPilhaCircular(&p);

    while (1) {
        if (PilhaCircularCheia(&p)) {
            printf("\nA pilha esta cheia. Deseja inserir mais um elemento? (S/N): ");
            char resposta;
            scanf(" %c", &resposta);
            if (resposta == 'N' || resposta == 'n') {
                break;
            }
        }

        printf("\nInforme uma letra para inserir na pilha: ");
        scanf(" %c", &letra);

        if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')) {
            EmpilharCircular(&p, letra);
        } else {
            printf("Por favor, insira apenas letras de A a Z ou a a z.\n");
        }
    }

    printf("\nPilha final: ");
    for (int i = 0; i < TAM; i++) {
        printf("_%c_|", p.vet[i]);
    }
    printf("\n");

    return 0;
}
