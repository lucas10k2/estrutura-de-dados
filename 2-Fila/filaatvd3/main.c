#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

#define TAM 2
// funcao que inserir funcionários
void EnfileirarFuncionarios(fila *f) {
    for (int i = 0; i < TAM; i++) {
        Funcionario *func = (Funcionario *)malloc(sizeof(Funcionario));
        printf("\nCPF: ");
        scanf("%s", func->CPF);
        printf("Nome: ");
        scanf("%s", func->nome);
        printf("Endereco: ");
        scanf("%s", func->endereco);
        printf("Telefone: ");
        scanf("%s", func->telefone);
        printf("Celular: ");
        scanf("%s", func->celular);
        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf("%s", func->dataNascimento);
        printf("Data de Admissao (dd/mm/aaaa): ");
        scanf("%s", func->dataAdmissao);
        printf("Departamento: ");
        scanf("%s", func->departamento);
        printf("Cargo: ");
        scanf("%s", func->cargo);
        printf("Salario: ");
        scanf("%f", &func->salario);

        Enfileirar(f, func);
    }
}
// funcao que desenfileirar o funcionário e gravar a fila em um arquivo binario
void DesenfileirarParaArquivoBinario(fila *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    while (!FilaVazia(f)) {
        Funcionario *func = Desenfileirar(f);
        fwrite(func, sizeof(Funcionario), 1, arquivo);
        free(func);
    }

    fclose(arquivo);
}
// funcao qu ler registros do arquivo e enfileira
void LerRegistrosDoArquivoEFila(fila *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Funcionario *func = (Funcionario *)malloc(sizeof(Funcionario));
    while (fread(func, sizeof(Funcionario), 1, arquivo)) {
        Enfileirar(f, func);
        func = (Funcionario *)malloc(sizeof(Funcionario));
    }
    free(func);

    fclose(arquivo);

    printf("Registros lidos do arquivo e enfileirados com sucesso.\n");
}
// funcao que pesquisar um funcionario pleo  CPF
void PesquisarPorCPF(fila *f, char *cpf) {
    fila temp;
    CriarFila(&temp);
    int encontrado = 0;

    while (!FilaVazia(f)) {
        Funcionario *func = Desenfileirar(f);
        if (strcmp(func->CPF, cpf) == 0) {
            printf("Funcionario encontrado:\n");
            printf("CPF: %s\nNome: %s\nEndereco: %s\nTelefone: %s\nCelular: %s\nData de Nascimento: %s\nData de Admissao: %s\nDepartamento: %s\nCargo: %s\nSalario: %.2f\n",
                func->CPF, func->nome, func->endereco, func->telefone, func->celular, func->dataNascimento, func->dataAdmissao, func->departamento, func->cargo, func->salario);
            encontrado = 1;
        }
        Enfileirar(&temp, func);
    }

    while (!FilaVazia(&temp)) {
        Funcionario *func = Desenfileirar(&temp);
        Enfileirar(f, func);
    }

    if (!encontrado) {
        printf("Funcionario com o CPF fornecido nao encontrado.\n");
    }
}

int main() {
    fila f;
    CriarFila(&f);

    printf("++++ Cadastro de Funcionarios ++++\n");

    // ler registros do teclado e enfileirar
    EnfileirarFuncionarios(&f);

    // desenfileirar um funcionário e gravar a fila em um arquivo binário
    DesenfileirarParaArquivoBinario(&f, "funcionarios.bin");

    // ler registros do arquivo e enfileirar
    CriarFila(&f); // reinicializar a fila para adicionar a partir do arquivo
    LerRegistrosDoArquivoEFila(&f, "funcionarios.bin");

    // pesquisar pelo CPF
    char cpfPesquisado[12];
    printf("Digite o CPF a ser pesquisado: ");
    scanf("%s", cpfPesquisado);
    PesquisarPorCPF(&f, cpfPesquisado);

    return 0;
}
