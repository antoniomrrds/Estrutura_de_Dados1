//TAD
typedef struct produto produto; 
struct produto{
	char descricao[40];
	int codigo;
	double preco;
	int quantidade;
	produto *produtosCliente;
};

//Bibliotecas


//Declarações globais

//Macros e constantes

//Protótipos
void menu();
