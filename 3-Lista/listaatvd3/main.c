#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 2

// Defini��o da estrutura de um funcion�rio
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

// Defini��o da lista de funcion�rios
typedef struct tipo_lista {
    elemento vet[TAM]; // Vetor para armazenar os funcion�rios
    int inicio, fim; // In�cio e fim da lista
} lista;

// Cria uma lista de funcion�rios vazia
void CriarLista(lista *l);

// Verifica se a lista de funcion�rios est� vazia
int ListaVazia(lista *l);

// Verifica se a lista de funcion�rios est� cheia
int ListaCheia(lista *l);

// Insere um funcion�rio na lista
void Alistar(lista *l, elemento e, int pos);

// Remove um funcion�rio da lista
elemento Desalistar(lista *l, int pos);

// Pesquisa um funcion�rio na lista pelo CPF
elemento PesquisarPorCPF(lista *l, long int cpf);

// Fun��o para criar uma lista vazia de funcion�rios
void CriarLista(lista *l) {
    (*l).inicio = 0;
    (*l).fim = 0;
}

// Fun��o para verificar se a lista de funcion�rios est� vazia
int ListaVazia(lista *l) {
    return ((*l).inicio == (*l).fim);
}

// Fun��o para verificar se a lista de funcion�rios est� cheia
int ListaCheia(lista *l) {
    return ((*l).fim == TAM);
}

// Fun��o para adicionar um funcion�rio � lista
void Alistar(lista *l, elemento e, int pos) {
    int i;
    if (ListaCheia(l))
        printf("A lista est� cheia. N�o � poss�vel inserir mais elementos.\n");
    else if ((pos < (*l).inicio) || (pos > (*l).fim)) {
        printf("Posi��o inv�lida! Posi��es v�lidas: [0, %d].\n", (*l).fim);
    } else {
        for (i = (*l).fim; i > pos; i--)
            (*l).vet[i] = (*l).vet[i - 1];
        (*l).vet[pos] = e;
        (*l).fim++;
    }
}

// Fun��o para remover um funcion�rio da lista
elemento Desalistar(lista *l, int pos) {
    int i;
    elemento e;
    if (ListaVazia(l))
        printf("A lista est� vazia. N�o � poss�vel retirar mais elementos.\n");
    else if ((pos < (*l).inicio) || (pos >= (*l).fim)) {
        printf("Posi��o inv�lida! Posi��es v�lidas: [0, %d].\n", (*l).fim - 1);
    } else {
        e = (*l).vet[pos];
        for (i = pos; i < ((*l).fim - 1); i++)
            (*l).vet[i] = (*l).vet[i + 1];
        (*l).fim--;
    }
    return e;
}

// Fun��o para pesquisar um funcion�rio na lista pelo CPF
elemento PesquisarPorCPF(lista *l, long int cpf) {
    elemento empty;
    empty.cpf = 0;
    if (ListaVazia(l)) {
        printf("A lista est� vazia. N�o h� elementos para pesquisar.\n");
        return empty;
    }

    for (int i = 0; i < (*l).fim; i++) {
        if ((*l).vet[i].cpf == cpf)
            return (*l).vet[i];
    }

    printf("Funcion�rio com o CPF fornecido n�o encontrado.\n");
    return empty;
}

int main() {
    lista l;
    CriarLista(&l);

    printf("++++ Cadastro de Funcion�rios ++++\n");

    // Exemplo de cria��o e inser��o de um funcion�rio na lista
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

    // Exemplo de pesquisa de um funcion�rio pelo CPF
    long int cpfPesquisado;
    printf("Digite o CPF a ser pesquisado: ");
    scanf("%ld", &cpfPesquisado);
    elemento funcionarioEncontrado = PesquisarPorCPF(&l, cpfPesquisado);
    if (funcionarioEncontrado.cpf != 0) {
        printf("Funcion�rio encontrado:\n");
        printf("CPF: %ld\n", funcionarioEncontrado.cpf);
        printf("Nome: %s\n", funcionarioEncontrado.nome);
        printf("Endere�o: %s\n", funcionarioEncontrado.endereco);
        printf("Telefone: %s\n", funcionarioEncontrado.telefone);
        printf("Celular: %s\n", funcionarioEncontrado.celular);
        printf("Data de Nascimento: %d/%d/%d\n", funcionarioEncontrado.data_nascimento.dia, funcionarioEncontrado.data_nascimento.mes, funcionarioEncontrado.data_nascimento.ano);
        printf("Data de Admiss�o: %d/%d/%d\n", funcionarioEncontrado.data_admissao.dia, funcionarioEncontrado.data_admissao.mes, funcionarioEncontrado.data_admissao.ano);
        printf("Departamento: %s\n", funcionarioEncontrado.departamento);
        printf("Cargo: %s\n", funcionarioEncontrado.cargo);
        printf("Sal�rio: %.2f\n", funcionarioEncontrado.salario);
    }

    return 0;
}
