// ... (o restante do código é o mesmo)

// Enfileira um elemento na lista.
void Enfileirar(lista *l, elemento e) {
    if (ListaCheia(l))
        printf("\n ERRO: lista cheia!");
    else {
        (*l).vet[(*l).fim] = e;
        (*l).fim++;
    }
}

// Desenfileira os elementos e os grava em um arquivo de texto.
void DesenfileirarParaArquivo(lista *l, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("\n ERRO: Não foi possível abrir o arquivo.");
        return;
    }

    for (int i = 0; i < (*l).fim; i++) {
        fprintf(file, "%f\n", (*l).vet[i]);
    }

    fclose(file);
}

// Enfileira os elementos a partir de um arquivo de texto.
void EnfileirarDoArquivo(lista *l, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("\n ERRO: Não foi possível abrir o arquivo.");
        return;
    }

    float num;
    while (fscanf(file, "%f", &num) != EOF) {
        Enfileirar(l, num);
    }

    fclose(file);
}
