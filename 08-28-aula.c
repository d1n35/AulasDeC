#include<stdlib.h>
#include<stdio.h>

void inserirLista(int nr);
void exibirLista(void);

struct no{
	int info;
	struct no *prox;
};

struct no *cabeca = NULL;
struct no *ant;

main(){
	inserirLista(10);
	inserirLista(20);
	inserirLista(30);
	exibirLista();
}

void inserirLista(int nr){
	struct no *novo;
	novo =(struct no*) malloc(sizeof(struct no));
	novo->info=nr;
	novo->prox=NULL;
	if(cabeca==NULL){
		cabeca=novo;
	}else{
		ant->prox=novo;
	}
	ant=novo;
}

void exibirLista(void){
	struct no *aux=cabeca;
	if(aux != NULL){
		while(aux->prox !=NULL){
			printf("%X %i -> %X \n",aux,aux->info,aux->prox);
			aux=aux->prox;
		}
		printf("%X %i -> %X \n",aux,aux->info,aux->prox);
	}else{
		printf("Lista vazia!");
	}
}
