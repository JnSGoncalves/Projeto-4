#define Tamanho_clientes 1000
#define Max_senha 25
#define Max_CPF 13 // 11 digitos mais o '\n' e o '\0'
#define Max_string 255
#define Max_extrato 100
#define Limite_Comum -1000
#define Limite_Plus -5000
#define Taxa_Comum 0.05F
#define Taxa_Plus 0.03F

typedef enum {comum, plus} Tipo_conta;
typedef enum {OK, Max_clientes_Erro, CPF_cadastrado, CPF_invalido, CPF_nao_cadastrado, Senha_incorreta, 
Valor_invalido, Saldo_negativo_excedido, Operacao_cancelada, Erro_abrir, Erro_escrever, Sem_extrato} Erros;

typedef enum {Debito, Deposito, Transferencia} Operacoes;

typedef struct {
    Operacoes tipo_operacao;
    float valor;
    float taxa;
    char operador;
} Extrato;


typedef struct {
    char cpf[Max_CPF];
    char nome[Max_string];
    Tipo_conta tipo_conta; // 0 = Conta comum; 1 = Conta plus
    float saldo;
    char senha[Max_senha];
    Extrato extrato[Max_extrato];
    int pos_extrato;
} conta;

int getIndex_cpf(const conta clientes[], int *pos);

int add_cliente(conta clientes[], int *pos);
int deletar_conta(conta clientes[], int *pos);
int listar_clientes(conta clientes[], const int *pos);
int debito(conta clientes[], int *pos);
int deposito(conta clientes[], int *pos);
int ver_extrato(conta clientes[], int *pos);
int transferencia(conta clientes[], int *pos);

int novo_extrato(conta clientes[], int pos_cpf, float valor, Operacoes tipo_operacao, char operador, float taxa);
int salvar(conta clientes[], int *pos);
int carregar(conta clientes[], int *pos);

void trat_erros(int erro);
void clearBuffer();

