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


//Declara��es globais

//Macros e constantes

//Prot�tipos
void menu();
