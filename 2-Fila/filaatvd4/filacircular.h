#ifndef FILACIRCULAR_H
#define FILACIRCULAR_H

#define TAM 5  // fila circular

typedef struct {
    char letra;
    int numero;
} elemento;

typedef struct {
    elemento vet[TAM];
    int inicio, fim;
    int quantidade;
} fila_circular;

// Inicializa a fila circular
void CriarFilaCircular(fila_circular *f);

// Verifica se a fila circular está vazia
int FilaCircularVazia(fila_circular *f);

// Verifica se a fila circular está cheia
int FilaCircularCheia(fila_circular *f);

// Adiciona um novo elemento à fila circular, substituindo o mais antigo se a fila estiver cheia
void EnfileirarCircular(fila_circular *f, char letra, int numero);

// Remove um elemento da fila circular
elemento DesenfileirarCircular(fila_circular *f);

#endif
