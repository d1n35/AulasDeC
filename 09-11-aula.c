#include <stdlib.h>
#include <stdio.h>

void exibirPilha(void);
void empilhar(int nr);
void desempilhar(void);

struct no{
	int info;
	struct no *prox;
};

struct no *topo = NULL;



void empilhar(int nr){
	
	struct no *novo;
	
	novo = (struct no *)malloc(sizeof(struct no));
	novo -> info = nr;
	
	if(topo == NULL){
		novo -> prox = NULL;
	}else{
		novo -> prox = topo;
	}
	
	topo = novo;
}

void exibirPilha(void){
	struct no *aux = topo;
	
	while(aux -> prox != NULL){
		printf("%x %i -> %x \n", aux,aux->info, aux->prox);
		aux = aux->prox;
	}
	printf("%x %i -> %x \n", aux,aux->info, aux->prox);
}

void desempilhar(void){
	struct no *auxiliar = topo;
	
	if(topo != NULL){
		topo = auxiliar ->prox;
		free(auxiliar);
	}else{
		printf("Pilha vazia!");
	}
}

main(){
	int opcao,num;
	system("cls");
	
	do{
		printf("Escolha uma opcao: \n");
		printf("1 - Empilhar \n");
		printf("2 - Desempilhar \n");
		printf("3 - Exibir lista \n");
		printf("4 - Sair \n");
		scanf("%i", &opcao);
		switch(opcao){
			case 1: printf("Digite o numero:");
					scanf("%i",&num);
					empilhar(num);
					break;
			case 2: desempilhar();
					printf("Topo desempilhado.");
					system("pause");
					break;
			case 3: exibirPilha();
					system("pause");
					break;
			case 4: printf("Fim do programa");
					break;
		}
	}while(opcao!=4);
	
}

