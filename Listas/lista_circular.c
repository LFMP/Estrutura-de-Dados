#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_item{
	int chave;
	/*outros campos*/
}item;

typedef struct tipo_celula{
	struct tipo_item item;
	struct tipo_celula *prox;
}celula;

typedef struct tipo_lista{
	celula *ultimo;
}lista;

void inicializa(lista *l){
	l->ultimo=NULL;
}

int vazia(lista *l){
	return l->ultimo == NULL;
}

struct tipo_celula *busca(lista *l, int chave){
	celula *ret,*ult;
	if(vazia(l)){
		return NULL;
	}else{
		ret = l->ultimo->prox;
		ult = l->ultimo;
		while((ret!=ult) && (chave!=ret->item.chave)){
			ret=ret->prox;
		}
		if(chave==ret->item.chave){
			return ret;
		}else{
			return NULL;
		}
	}
}

void insere_ultimo(lista *l, item x){
	celula *novo;
	novo=(celula *)malloc(sizeof(celula));
	novo->item=x;
	if(vazia(l)){
		novo->prox=novo;
	}else{
		novo->prox=l->ultimo->prox;
		l->ultimo->prox=novo;
	}
	l->ultimo=novo;
}

void insere_inicio(lista *l, item x){
	celula *novo;
	if(vazia(l)){
		insere_ultimo(l,x);
	}else{
		novo=(struct tipo_celula *)malloc(sizeof(struct tipo_celula));
		novo->item=x;
		novo->prox=l->ultimo->prox;
		l->ultimo->prox=novo;
	}
}

int remove_inicio(lista *l, item *retorno){
	celula *aux;
	if(vazia(l)){
		return 0;
	}
	aux = l->ultimo->prox;
	*retorno = aux->item;
	if (l->ultimo != l->ultimo->prox){
		l->ultimo->prox = aux->	prox;
		free(aux);
		return 1;
	}
	l->ultimo = NULL;
	free(aux);
	return 1;
}

void escreve(lista *l){
	celula *ptr;
	printf("--------------------------------\n");
	if(!vazia(l)){
		ptr=l->ultimo->prox;
		do{
			printf("%d ",ptr->item.chave);
			ptr=ptr->prox;
		}while(ptr!=l->ultimo->prox);
		printf("\n");
	}else{
		printf("lista vazia\n");
	}
	printf("--------------------------------\n");
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
		printf("[3] Inserir apos X posicoes\n");
		printf("[4] Remover primeiro elemento\n");
		printf("[5] Remover ultimo elemento\n");
		printf("[6] Remover na posicao X\n");
		printf("[7] Buscar um elemento por chave\n");
		printf("[8] Printar lista\n");
		printf("[9] Ordenar lista\n");
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
				insere_inicio(&l,i);	
			break;

			case 3:
				printf("digite a chave:");
				scanf("%d",&i.chave);
				printf("digite a posicao:");
				scanf("%d",&pos);
				insere_apos(&l,i,pos);	
			break;

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
			break;
		}
	}while(op!=0);
}