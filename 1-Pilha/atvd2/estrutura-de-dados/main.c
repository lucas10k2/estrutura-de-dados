#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 10 // mudei para atender a seguencia da atvd
typedef float elemento;
#include "pilha.h"

// procedimento para desempilhar os elementos e gravar em um arquivo texto
void DesempilharParaArquivo(pilha *p, const char *nome_arquivo) {
    // abre o arquivo para escrita
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    // desempilha os elementos e os grava no arquivo
    while (PilhaVazia(p) == false) {
        elemento num = Desempilhar(p);
        fprintf(arquivo, "%f\n", num);  // Grava o número no arquivo
    }

    fclose(arquivo);  // Fecha o arquivo
}

// procedimento para ler os elementos a partir do arquivo no modo texto e empilhar
void LerDoArquivoEEmpilhar(pilha *p, const char *nome_arquivo) {
    // abre o arquivo para leitura
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    // le os numeros do arquivo e os empilha
    elemento num;
    while (fscanf(arquivo, "%f", &num) != EOF) {
        Empilhar(p, num);  // empilha o numero lido do arquivo
    }

    fclose(arquivo);  // fecha o arquivo
}

// procedimento para imprimir o conteudo da pilha
void ImprimirPilha(pilha *p) {
    printf("\nConteudo da pilha: \n");
    while (PilhaVazia(p) == false) {
        elemento num = Desempilhar(p);
        printf("%f\n", num);  // imprime o numero na tela
    }
}

int main() {
    pilha p;
    CriarPilha(&p);

    printf("Digite 10 numeros reais:\n");
    for (int i = 0; i < 10; i++) {
        elemento num;
        scanf("%f", &num);
        Empilhar(&p, num);  // empilha os numeros
    }

    DesempilharParaArquivo(&p, "numeros.txt");  // desempilha e grava no arquivo
    CriarPilha(&p);
    LerDoArquivoEEmpilhar(&p, "numeros.txt");  // le do arquivo e empilha de volta
    ImprimirPilha(&p);  // imprime o conteudo da pilha na tela

    return 0;
}
