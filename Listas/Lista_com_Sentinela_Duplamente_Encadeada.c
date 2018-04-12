#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_item{
	int chave;
}item;

typedef struct tipo_celula{ 
	struct tipo_item item;
	struct tipo_celula *prox;
	struct tipo_celula *ant;
}celula;

typedef struct tipo_lista{
	struct tipo_celula *primeiro;
}lista;

void inicializa(lista* l){
	l->primeiro = (celula*)malloc(sizeof(celula));
	l->primeiro->prox = l->primeiro;
	l->primeiro->ant = l->primeiro;
}

int vazia(lista* l){
	return l->primeiro->prox == l->primeiro;
}

void insere_primeiro(lista *l, item i){
	celula *novo = (celula*)malloc(sizeof(celula));
	novo->item = i;
	novo->ant = l->primeiro;
	novo->prox = l->primeiro->prox;
	l->primeiro->prox = novo;
	l->primeiro->ant = novo;
}

void insere_ultimo(lista* l, item x){
	celula *c = (celula*)malloc(sizeof(celula));
	c->item = x;
	c->prox = l->primeiro;
	c->ant = l->primeiro->ant;
	l->primeiro->ant->prox = c;
	l->primeiro->ant = c;
}

int insere_pos(lista* l, item insert, int i){
	celula *aux = l->primeiro->prox;
	celula *novo;
	int cont = 0;
	while(aux != l->primeiro && cont < i){
		aux = aux->prox;
	}
	if(i == cont){
		novo = (celula*)malloc(sizeof(celula));
		novo->item = insert;
		novo->prox = aux->prox;
		novo->ant = aux;
		aux->prox = novo;
		novo->prox->ant = novo;
		return 1;
	}
	return 0;
}

int main(){
	lista l;
	item i;
	int op,pos;
	inicializa(&l);
	op=1;
	do{
		printf("[1] Inserir elemento no fim\n");
		printf("[2] Inserir elemento no inicio\n");
		printf("[3] Inserir apos X posicoes\n");/*
		printf("[4] Remover primeiro elemento\n");
		printf("[5] Remover ultimo elemento\n");
		printf("[6] Remover na posicao X\n");
		printf("[7] Buscar um elemento por chave\n");
		printf("[8] Printar lista\n");
		printf("[9] Ordenar lista\n");*/
		scanf("%d",&op);

		switch(op){
			case 1:
				printf("digite a chave:");
				scanf("%d",&i.chave);
				insere_ultimo(&l,i);
			break;

			case 2:
				printf("digite a chave:");
				scanf("%d",&i.chave);
				insere_primeiro(&l,i);	
			break;

			case 3:
				printf("digite a chave:");
				scanf("%d",&i.chave);
				printf("digite a posicao:");
				scanf("%d",&pos);
				insere_pos(&l,i,pos);	
			break;
			/*
			case 4:
				if(remove_inicio(&l,&i)){
					printf("excluiu: %d\n",i.chave);
				}else{
					printf("nao foi possivel remover\n");
				}
			break;

			case 5:
				if(remove_ultimo(&l,&i)){
					printf("excluiu: %d\n",i.chave);
				}else{
					printf("nao foi possivel remover\n");
				}
			break;

			case 7:
				printf("buscar por:");
				scanf("%d",&i.chave);
				if(busca(&l,i.chave)!=NULL){
					printf("elemento encontrado\n");	
				}else{
					printf("elemento nao encontrado\n");	
				}
			break;

			case 8:
				escreve(&l);
			break;*/
		}
	}while(op!=0);
}