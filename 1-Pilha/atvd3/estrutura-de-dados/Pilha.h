#define TAM 2
#define VERDADEIRO 1
#define FALSO 0
//funcionario
typedef struct {
    char CPF[12];
    char nome[50];
    char endereco[100];
    char telefone[15];
    char celular[15];
    char dataNascimento[11];
    char dataAdmissao[11];
    char departamento[50];
    char cargo[50];
    float salario;
} Funcionario;
//estrutura de pilha
struct tipo_pilha {
    Funcionario vet[TAM];
    int topo;
};

typedef struct tipo_pilha pilha;
// funcao para criar uma pilha vazia
void CriarPilha(pilha *p);
// funcao para verificar se a pilha esta vazia
int PilhaVazia(pilha *p);
// funcao para verificar se a pilha esta cheia
int PilhaCheia(pilha *p);
// funcao para empilhar um funcionario na pilha
void Empilhar(pilha *p, Funcionario f);
// funcao para desempilhar um funcionario da pilha
Funcionario Desempilhar(pilha *p);
// funcao para gravar a pilha em um arquivo binario
void GravarPilhaEmArquivo(pilha *p, const char *nomeArquivo);
// funcao para ler registros do teclado e empilhar
void LerRegistrosDoTecladoEPilhar(pilha *p);
// funcao para ler registros de um arquivo no modo binario e empilhar
void LerRegistrosDoArquivoEPilhar(pilha *p, const char *nomeArquivo);
// funcao para pesquisar um funcionario por CPF
Funcionario PesquisarPorCPF(pilha *p, char *cpf);
