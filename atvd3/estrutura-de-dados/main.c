#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"


// funcao para criar uma pilha vazia
void CriarPilha(pilha *p) {
    (*p).topo = 0;
}
// funcao que verificar se a pilha esta vazia
int PilhaVazia(pilha *p) {
    return ((*p).topo == 0);
}
// funcao que verificar se a pilha esta cheia
int PilhaCheia(pilha *p) {
    return ((*p).topo == TAM);
}
// funcao que empilhar um funcionario
void Empilhar(pilha *p, Funcionario f) {
    if (PilhaCheia(p)) {
        printf("A pilha esta cheia. Nao e possivel empilhar mais elementos.\n");
        return;
    }
    (*p).vet[(*p).topo] = f;
    (*p).topo++;
}
// funcao para desempilhar um funcionário
Funcionario Desempilhar(pilha *p) {
    if (PilhaVazia(p)) {
        printf("A pilha esta vazia. Nao e possivel desempilhar mais elementos.\n");
        Funcionario f_empty;
        memset(&f_empty, 0, sizeof(f_empty));
        return f_empty;
    }
    (*p).topo--;
    return (*p).vet[(*p).topo];
}
// funcao para gravar a pilha em um arquivo binário
void GravarPilhaEmArquivo(pilha *p, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    fwrite(p, sizeof(pilha), 1, arquivo);

    fclose(arquivo);
}
// funcao ler registros do teclado e empilhar
void LerRegistrosDoTecladoEPilhar(pilha *p) {
    for (int i = 0; i < TAM; i++) {
        Funcionario f;
        printf("\nCPF: ");
        scanf("%s", f.CPF);
        printf("Nome: ");
        scanf("%s", f.nome);
        printf("Endereco: ");
        scanf("%s", f.endereco);
        printf("Telefone: ");
        scanf("%s", f.telefone);
        printf("Celular: ");
        scanf("%s", f.celular);
        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf("%s", f.dataNascimento);
        printf("Data de Admissão (dd/mm/aaaa): ");
        scanf("%s", f.dataAdmissao);
        printf("Departamento: ");
        scanf("%s", f.departamento);
        printf("Cargo: ");
        scanf("%s", f.cargo);
        printf("Salario: ");
        scanf("%f", &f.salario);

        Empilhar(p, f);
    }
}
// funcao que ler registros de um arquivo binario e empilhar
void LerRegistrosDoArquivoEPilhar(pilha *p, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    fread(p, sizeof(pilha), 1, arquivo);

    fclose(arquivo);

    printf("Registros lidos do arquivo e empilhados com sucesso.\n");
}
// funcao que pesquisa um funcionario pelo cpf
Funcionario PesquisarPorCPF(pilha *p, char *cpf) {
    for (int i = 0; i < (*p).topo; i++) {
        if (strcmp((*p).vet[i].CPF, cpf) == 0) {
            return (*p).vet[i];
        }
    }
    Funcionario f_empty;
    memset(&f_empty, 0, sizeof(f_empty));
    printf("Funcionario com o CPF fornecido nao encontrado.\n");
    return f_empty;
}

int main() {
    pilha p;
    CriarPilha(&p);

    printf("++++ Cadastro de Funcionarios ++++\n");

    // lee registro do teclado e empilhar
    LerRegistrosDoTecladoEPilhar(&p);

    // desempilhar um funcionário e gravar a pilha em um arquivo binari
    Funcionario funcionarioDesempilhado = Desempilhar(&p);
    GravarPilhaEmArquivo(&p, "funcionarios.bin");

    //ler registros do arquivo e empilhar
    LerRegistrosDoArquivoEPilhar(&p, "funcionarios.bin");

    // pesquisar pelo CPF
    char cpfPesquisado[12];
    printf("Digite o CPF a ser pesquisado: ");
    scanf("%s", cpfPesquisado);
    Funcionario funcionarioEncontrado = PesquisarPorCPF(&p, cpfPesquisado);
    if (strcmp(funcionarioEncontrado.CPF, "") != 0) {
        printf("Funcionario encontrado:\n");
        printf("CPF: %s\n", funcionarioEncontrado.CPF);
        printf("Nome: %s\n", funcionarioEncontrado.nome);
        printf("Endereco: %s\n", funcionarioEncontrado.endereco);
        printf("Telefone: %s\n", funcionarioEncontrado.telefone);
        printf("Celular: %s\n", funcionarioEncontrado.celular);
        printf("Data de Nascimento: %s\n", funcionarioEncontrado.dataNascimento);
        printf("Data de Admissão: %s\n", funcionarioEncontrado.dataAdmissao);
        printf("Departamento: %s\n", funcionarioEncontrado.departamento);
        printf("Cargo: %s\n", funcionarioEncontrado.cargo);
        printf("Salario: %.2f\n", funcionarioEncontrado.salario);
    }

    return 0;
}
