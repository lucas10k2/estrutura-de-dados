#include <stdio.h>
#include <stdlib.h>
#define TAM 10
typedef float elemento;
#include "fila.h"

// desenfileirar e gravar no arquivo txt
void DesenfileirarParaArquivo(fila *f, const char* filename) {
    FILE *arquivo;
    arquivo = fopen(filename, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    while (!FilaVazia(f)) {
        elemento num = Desenfileirar(f);
        fprintf(arquivo, "%f\n", num);
    }
    fclose(arquivo);
}

// ler os arquivos dentro do txt e enfileirar novamente
void EnfileirarDoArquivo(fila *f, const char* filename) {
    FILE *arquivo;
    arquivo = fopen(filename, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    elemento num;
    while (fscanf(arquivo, "%f", &num) != EOF) {
        Enfileirar(f, num);
    }
    fclose(arquivo);
}

// imprimir na tela o conteudo da fila
void ImprimirFila(fila *f) {
    printf("\nConteudo da fila:\n");
    int i;
    for (i = f->inicio; i < f->fim; i++) {
        printf("%f\n", f->vet[i]);
    }
}

int main() {
    float num;
    fila f;
    CriarFila(&f);

    // enfileirando 10 numeros reais a partir do teclado
    printf("Digite 10 numeros reais:\n");
    for (int i = 0; i < 10; i++) {
        printf("Informe um numero real: ");
        scanf("%f", &num);
        Enfileirar(&f, num);
    }

    // desenfileirando os elementos e gravando em um arquivo de texto
    DesenfileirarParaArquivo(&f, "numeros.txt");

    // lendo os elementos de um arquivo de texto e enfileirando-os
    CriarFila(&f); // reinicializa a fila para adicionar a partir do arquivo
    EnfileirarDoArquivo(&f, "numeros.txt");

    // imprimindo o conteudo
    ImprimirFila(&f);

    return 0;
}
