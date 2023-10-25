#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 2

// Definição da estrutura de um funcionário
typedef struct {
    long int cpf;
    char nome[50];
    char endereco[100];
    char telefone[20];
    char celular[20];
    struct tipo_data {
        int dia, mes, ano;
    } data_nascimento, data_admissao;
    char departamento[50];
    char cargo[50];
    float salario;
} elemento;

// Definição da lista de funcionários
typedef struct tipo_lista {
    elemento vet[TAM]; // Vetor para armazenar os funcionários
    int inicio, fim; // Início e fim da lista
} lista;

// Cria uma lista de funcionários vazia
void CriarLista(lista *l);

// Verifica se a lista de funcionários está vazia
int ListaVazia(lista *l);

// Verifica se a lista de funcionários está cheia
int ListaCheia(lista *l);

// Insere um funcionário na lista
void Alistar(lista *l, elemento e, int pos);

// Remove um funcionário da lista
elemento Desalistar(lista *l, int pos);

// Pesquisa um funcionário na lista pelo CPF
elemento PesquisarPorCPF(lista *l, long int cpf);

// Função para criar uma lista vazia de funcionários
void CriarLista(lista *l) {
    (*l).inicio = 0;
    (*l).fim = 0;
}

// Função para verificar se a lista de funcionários está vazia
int ListaVazia(lista *l) {
    return ((*l).inicio == (*l).fim);
}

// Função para verificar se a lista de funcionários está cheia
int ListaCheia(lista *l) {
    return ((*l).fim == TAM);
}

// Função para adicionar um funcionário à lista
void Alistar(lista *l, elemento e, int pos) {
    int i;
    if (ListaCheia(l))
        printf("A lista está cheia. Não é possível inserir mais elementos.\n");
    else if ((pos < (*l).inicio) || (pos > (*l).fim)) {
        printf("Posição inválida! Posições válidas: [0, %d].\n", (*l).fim);
    } else {
        for (i = (*l).fim; i > pos; i--)
            (*l).vet[i] = (*l).vet[i - 1];
        (*l).vet[pos] = e;
        (*l).fim++;
    }
}

// Função para remover um funcionário da lista
elemento Desalistar(lista *l, int pos) {
    int i;
    elemento e;
    if (ListaVazia(l))
        printf("A lista está vazia. Não é possível retirar mais elementos.\n");
    else if ((pos < (*l).inicio) || (pos >= (*l).fim)) {
        printf("Posição inválida! Posições válidas: [0, %d].\n", (*l).fim - 1);
    } else {
        e = (*l).vet[pos];
        for (i = pos; i < ((*l).fim - 1); i++)
            (*l).vet[i] = (*l).vet[i + 1];
        (*l).fim--;
    }
    return e;
}

// Função para pesquisar um funcionário na lista pelo CPF
elemento PesquisarPorCPF(lista *l, long int cpf) {
    elemento empty;
    empty.cpf = 0;
    if (ListaVazia(l)) {
        printf("A lista está vazia. Não há elementos para pesquisar.\n");
        return empty;
    }

    for (int i = 0; i < (*l).fim; i++) {
        if ((*l).vet[i].cpf == cpf)
            return (*l).vet[i];
    }

    printf("Funcionário com o CPF fornecido não encontrado.\n");
    return empty;
}

int main() {
    lista l;
    CriarLista(&l);

    printf("++++ Cadastro de Funcionários ++++\n");

    // Exemplo de criação e inserção de um funcionário na lista
    elemento f;
    f.cpf = 12345678910;  // Exemplo de CPF
    strcpy(f.nome, "Fulano");
    strcpy(f.endereco, "Rua ABC, 123");
    strcpy(f.telefone, "1112345678");
    strcpy(f.celular, "11987654321");
    f.data_nascimento.dia = 1;
    f.data_nascimento.mes = 1;
    f.data_nascimento.ano = 1990;
    f.data_admissao.dia = 1;
    f.data_admissao.mes = 1;
    f.data_admissao.ano = 2020;
    strcpy(f.departamento, "Departamento A");
    strcpy(f.cargo, "Cargo B");
    f.salario = 5000.0;

    Alistar(&l, f, 0);

    // Exemplo de pesquisa de um funcionário pelo CPF
    long int cpfPesquisado;
    printf("Digite o CPF a ser pesquisado: ");
    scanf("%ld", &cpfPesquisado);
    elemento funcionarioEncontrado = PesquisarPorCPF(&l, cpfPesquisado);
    if (funcionarioEncontrado.cpf != 0) {
        printf("Funcionário encontrado:\n");
        printf("CPF: %ld\n", funcionarioEncontrado.cpf);
        printf("Nome: %s\n", funcionarioEncontrado.nome);
        printf("Endereço: %s\n", funcionarioEncontrado.endereco);
        printf("Telefone: %s\n", funcionarioEncontrado.telefone);
        printf("Celular: %s\n", funcionarioEncontrado.celular);
        printf("Data de Nascimento: %d/%d/%d\n", funcionarioEncontrado.data_nascimento.dia, funcionarioEncontrado.data_nascimento.mes, funcionarioEncontrado.data_nascimento.ano);
        printf("Data de Admissão: %d/%d/%d\n", funcionarioEncontrado.data_admissao.dia, funcionarioEncontrado.data_admissao.mes, funcionarioEncontrado.data_admissao.ano);
        printf("Departamento: %s\n", funcionarioEncontrado.departamento);
        printf("Cargo: %s\n", funcionarioEncontrado.cargo);
        printf("Salário: %.2f\n", funcionarioEncontrado.salario);
    }

    return 0;
}
