#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10
#define MAX_LENGTH 100

typedef struct {
    char cpf[15];
    char nome[MAX_LENGTH];
    char endereco[MAX_LENGTH];
    char telefone[15];
    char celular[15];
    char data_nascimento[11];
    char data_admissao[11];
    char departamento[MAX_LENGTH];
    char cargo[MAX_LENGTH];
    double salario;
} Funcionario;

// Cria lista.
void CriarLista(Funcionario *funcionarios);

// Verifica se a lista est� vazia.
int ListaVazia(Funcionario *funcionarios);

// Verifica se a lista est� cheia.
int ListaCheia(Funcionario *funcionarios);

// Insere um funcion�rio na lista.
void Alistar(Funcionario *funcionarios, Funcionario novoFuncionario, int pos);

// Retira um funcion�rio da lista.
void Desalistar(Funcionario *funcionarios, int pos);

// Fun��o para pesquisar funcion�rios por CPF.
int PesquisarPorCPF(Funcionario *funcionarios, char *cpf);
