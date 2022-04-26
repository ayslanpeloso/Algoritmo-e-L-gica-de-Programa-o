#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#define MAX 200

typedef struct dados{
	int codigo;
	char nome[30], descricao[100], ano[6], status[4], gerente[50], orcamento[10], colaboradores[8], duracao[8];

}base_projetos;

int posicao = 0;

void cadastrarProjeto(base_projetos cadastro[MAX]);
void relatorioProjeto(base_projetos cadastro[MAX]);
void buscarStatus(base_projetos cadastro[MAX]);
void buscarNome(base_projetos cadastro[MAX]);

int main(){
	setlocale(LC_ALL, "Portuguese");
	base_projetos cadastro[MAX];
	
	int escolha;
	
	system("cls");	
	do{
		system("cls");
		printf("****************************************************");
		printf("\n GESTÃO DE PROJETO ");
		printf("\n****************************************************");
		printf("\n 1 - Cadastro");
		printf("\n 2 - Lista dos Projetos Cadastrados");
		printf("\n 3 - Busca por Status (sendo 1 para 'A Fazer'; 2 para 'Fazendo' e 3 para 'Concluido')");
		printf("\n 4 - Busca por Nome");
		printf("\n 5 - Sair");
		printf("\n << Escolha uma opção do menu: ");
		scanf("%d", &escolha);
		
		switch(escolha){
			case 1:
				cadastrarProjeto(cadastro);			
				break;
			case 2:
				relatorioProjeto(cadastro);
				break;
			case 3:
				buscarStatus(cadastro);
				break;
			case 4:
				buscarNome(cadastro);
				break;
			case 5:
				printf("\nSaindo da Aplicação\n");
				system("Pause");
				break;
			default:
				printf("\nEscolha errada!!!\n");
				system("Pause");
		}
	}while(escolha != 5);
	return 0;
}

void cadastrarProjeto(base_projetos cadastro[MAX]){
	system("cls");
	printf("***************************************");
	printf("\n NOVO CADASTRO DE PROJETO");
	printf("\n***************************************");
	char resp = 's';
	
	while(resp == 's' && posicao <= MAX){
		posicao++;
		
		printf("\nCódigo: %d ", posicao);
		//scanf("%d", &cadastro[posicao].codigo);
		cadastro[posicao].codigo = posicao;
		
		printf("\nInforme o Nome do Projeto: ");
		fflush(stdin);
		gets(cadastro[posicao].nome);
		
		printf("\nInforme a Descricao do Projeto: ");
		fflush(stdin);
		gets(cadastro[posicao].descricao);
		
		printf("\nInforme o Ano do Projeto: ");
		fflush(stdin);
		gets(cadastro[posicao].ano);
		
		printf("\nInforme o Codigo do Status do Projeto (sendo 1 para 'A Fazer'; 2 para 'Fazendo' e 3 para 'Concluido'): ");
		fflush(stdin);
		gets(cadastro[posicao].status);
		
		printf("\nInforme o Gerente Responsavel do Projeto: ");
		fflush(stdin);
		gets(cadastro[posicao].gerente);
		
		printf("\nInforme o Orcamento Inicial Previsto para o Projeto: ");
		fflush(stdin);
		gets(cadastro[posicao].orcamento);
		
		printf("\nInforme a Quantidade de Colaboradores na Equipe desse Projeto: ");
		fflush(stdin);
		gets(cadastro[posicao].colaboradores);
		
		printf("\nInforme a Duracao Inicial Prevista para o Projeto (em meses): ");
		fflush(stdin);
		gets(cadastro[posicao].duracao);
			
		if(posicao < MAX){
			printf("\n\nDeseja cadastrar novo Projeto? [s] Sim [n] Não: ");
			fflush(stdin);
			scanf("%c", &resp);
		}else{
			printf("\nSua base de Dados já chegou ao limite!!!\n");
			resp = 'n';
		}
	}
}

void relatorioProjeto(base_projetos cadastro[MAX]){
	system("cls");
	printf("***************************************");
	printf("\n RELATORIO DOS PROJETOS CADASTRADOS");
	printf("\n***************************************\n");
	int linha=1;
	
	if(posicao >= 1){
		while(linha <= posicao){
			printf("Codigo: %d\nNome: %s\nDescricao: %s\nAno: %s\nStatus: %s\nGerente: %s\nColaboradores: %s\nDuracao: %s\n\n", cadastro[linha].codigo,
			cadastro[linha].nome, cadastro[linha].descricao, cadastro[linha].ano, cadastro[linha].status, cadastro[linha].gerente, cadastro[linha].colaboradores,
			cadastro[linha].duracao);
			linha++;
		}	
			
	}else{
		printf("\nSem Registros Cadastrados\n");
	}	
	system("Pause");
}

void buscarStatus(base_projetos cadastro[MAX])
{
	system("cls");
	char status[4];
	int achou, j, codigo;
	printf("***********************************************************************************");
	printf("\n BUSCA POR STATUS (sendo 1 para 'A Fazer'; 2 para 'Fazendo' e 3 para 'Concluido')");
	printf("\n********************************************************************************");
	printf("\nEntre Status Desejado (sendo 1 para 'A Fazer'; 2 para 'Fazendo' e 3 para 'Concluido'): ");
	fflush(stdin);
	gets(status);
	achou = 0;
	j = 0;
	while((achou == 0) && (j < MAX)){
		if(strcmp(cadastro[j].status,status)==0){
			printf("Codigo: %d\nNome: %s\nDescricao: %s\nAno: %s\nStatus: %s\nGerente: %s\nColaboradores: %s\nDuracao: %s\n\n",
			cadastro[j].codigo,	cadastro[j].nome, cadastro[j].descricao, cadastro[j].ano, cadastro[j].status, cadastro[j].gerente, cadastro[j].colaboradores,
			cadastro[j].duracao);
			achou <= codigo;
			system("Pause");
		}
		j++;
	}
	if(achou == 0 ){
		printf("\nRegistro não encontrado com o codigo %s \n", status);
		system("Pause");
	}
}
void buscarNome(base_projetos cadastro[MAX]){
	system("cls");
	char nome[30];
	int achou, j;
	printf("***************************************");
	printf("\n BUSCA POR NOME ");
	printf("\n***************************************");
	printf("\nEntre com o nome (idêntico ao digitado): ");
	fflush(stdin);
	gets(nome);
	achou = 0;
	j = 0;
	while((achou == 0) && (j < MAX)){
		if(strcmp(cadastro[j].nome,nome)==0){
			printf("Codigo: %d\nNome: %s\nDescricao: %s\nAno: %s\nStatus: %s\nGerente: %s\nColaboradores: %s\nDuracao: %s\n\n",
			cadastro[j].codigo,	cadastro[j].nome, cadastro[j].descricao, cadastro[j].ano, cadastro[j].status, cadastro[j].gerente, cadastro[j].colaboradores,
			cadastro[j].duracao);
			achou = 1;
			system("Pause");
		}
		j++;
	}
	if(achou == 0 ){
		printf("\nRegistro não encontrado com o nome %s \n", nome);
		system("Pause");
	}
}

