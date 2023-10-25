#define TAM 10
typedef float elemento;

typedef struct tipo_lista {
    elemento vet[TAM];
    int inicio, fim;
} lista;

void CriarLista(lista *l) {
    (*l).inicio = 0;
    (*l).fim = 0;
}

int ListaVazia(lista *l) {
    return ((*l).inicio == (*l).fim);
}

int ListaCheia(lista *l) {
    return ((*l).fim == TAM);
}

void Enfileirar(lista *l, elemento e) {
    if (ListaCheia(l))
        printf("\n ERRO: lista cheia!");
    else {
        (*l).vet[(*l).fim] = e;
        (*l).fim++;
    }
}

void DesenfileirarParaArquivo(lista *l, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("\n ERRO: Nao foi possivel abrir o arquivo.");
        return;
    }

    for (int i = 0; i < (*l).fim; i++) {
        fprintf(file, "%f\n", (*l).vet[i]);
    }

    fclose(file);
}

void EnfileirarDoArquivo(lista *l, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("\n ERRO: Nao foi possivel abrir o arquivo.");
        return;
    }

    float num;
    while (fscanf(file, "%f", &num) != EOF) {
        Enfileirar(l, num);
    }

    fclose(file);
}

void ImprimeLista(lista *l) {
    if (ListaVazia(l)) {
        printf("\nLista vazia\n");
    } else {
        printf("\nConteudo da lista:\n");
        for (int i = (*l).inicio; i < (*l).fim; i++) {
            printf("%f ", (*l).vet[i]);
        }
        printf("\n");
    }
}

void ImprimeArquivo(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("\n ERRO: Nao foi possivel abrir o arquivo.");
        return;
    }

    printf("\nConteudo do arquivo:\n");
    float num;
    while (fscanf(file, "%f", &num) != EOF) {
        printf("%f ", num);
    }
    printf("\n");

    fclose(file);
}
