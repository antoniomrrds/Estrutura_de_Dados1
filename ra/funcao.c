#include "biblioteca.h"



//Menu
void menu(void){
    char opcao;
    int qtde;
    int i,x;
    
    char *frasePersonalizada;
  

    do{

        printf("\n A- Inserir dados dos funcionarios. \n B- Exibir informacoes. \n C- Finlizar o programa.\n");
        printf("\n Escolha uma das opcoes: ");
        scanf("%c ", &opcao);
        opcao = toupper(opcao);
        switch (opcao){
        case 'A':

            do{
                printf("Digite a quantidade de funcionários da empresa: ");
                scanf(" %i", &qtde);
                if(qtde < 1){
                    printf("Quantidade deve ser maior que 0");
                }
            }while(qtde < 1);

            funcionario *func = alocarVetorFuncionario(qtde);
            
            for(i =0; i<qtde;i++){
            
                //NOME
                frasePersonalizada = "\nDigite o nome do Funcionario:";
                cadastrarNome(func[i].nome, frasePersonalizada);
                //CÓDIGO
                func[i].codigo = RANDOM;
                //SALÁRIO
                solicitarSalario(&func[i].salario);
                //QTDE DEPENDENTES
                cadastrarQuantidade(&func[i].numDependentes, MAXCADASTRO);
                //ALOC DIN. VET. DEPENDENTE
                dependente *dep = alocarVetorDependente(func[i].numDependentes);

                //PREENCHENDO VET. DEP.
                for(x=0; x<func[i].numDependentes; x++){
                    //NOME
                    frasePersonalizada = "\nDigite o nome do Dependente:";
                    cadastrarNome(dep[x].nome, frasePersonalizada);
                    //COD DEP.
                    dep[x].codigoDependente = MULT(func[i].codigo, x);
                    //IDADE
                    cadastrarQuantidade(&dep[x].idade, 18);
                    //
                    func[i].dadosDependentes[x] = dep[x];
                    printf("idade teste: %i", func[i].dadosDependentes[x].idade);
                }

            }


            break;
        case 'B':
            imprimirResultado(qtde, func);
            break;
        case 'C':
            exit(0);
            break;
        default:
            printf("Opcao invalida! Digite novamente");
            break;
        }
    }while (opcao != 'C');
}

//OPÇÃO A
//q1
funcionario*alocarVetorFuncionario(int qtde){
    funcionario *func = NULL;
    func = (funcionario*) malloc(qtde * sizeof(funcionario));
    return func;
}
//q2
void cadastrarNome(char *nome, char *frasePersonalizada){
    do {
        printf("%s",frasePersonalizada);
        scanf(" %[^\n]", nome);

        if (strlen(nome) == 0) {
            printf("\nDigite o nome corretamente.");
        }
    } while (strlen(nome) == 0);
}
//q6
void cadastrarQuantidade(int *quantidadeSolicitada, int valorMaximoPermitido){
    do{
        printf("Digite a quantidade de dependentes ou idade do dependente: ");
        scanf(" %i", quantidadeSolicitada);
        if((*quantidadeSolicitada < 0) || *quantidadeSolicitada > valorMaximoPermitido){
            printf("Valor Inválido, deve estar entre 0 e %i!\n", valorMaximoPermitido);
        }
    }while((*quantidadeSolicitada < 0) || *quantidadeSolicitada > valorMaximoPermitido);
}
//q7
void solicitarSalario(float *salario){
   do{
        printf("Digite o salario: ");
        scanf(" %f", salario);
        if(*salario < 0){
            printf("Valor invalido, deve ser maior que 0!\n");
        }
   }while(*salario < 0);

}

//q8
dependente*alocarVetorDependente(int qtde){
    dependente *dep = NULL;
    dep = (dependente*) malloc(qtde * sizeof(dependente));
    return dep;
}

//IMPRIMIR
void imprimirResultado(int qtde, funcionario *func){
	int i,x;
    printf("=====================================");
    printf("Colaboradores da Empresa");
    printf("=====================================");
    for(i=0; i<qtde; i++){
            printf("\t\nFuncionario %s \nCódigo = %i \nSalario = %.2f \nNúmero de Dependentes = %i", func[i].nome, func[i].codigo, func[i].salario, func[i].numDependentes);
        for(x=0; x<func[i].numDependentes; x++){
            printf("\n=====================================");
            printf("\nDependentes do Funcionario %s", func[i].nome);
            printf("\t\nNome: %s\n", func[i].dadosDependentes[x].nome);
            printf("\tCódigo: %i\n", func[i].dadosDependentes[x].codigoDependente);
            printf("\tIdade: %i\n", func[i].dadosDependentes[x].idade);

        }
    }
}














