#include <iostream>
#include <string.h>

using namespace std;

struct celula
{
	int id;
	char caracteres[30];
	celula *prox;
	celula *anter;
};

struct lista
{
	celula *inicio;
	celula *fim;
	int tam;
};

bool Lista_vazia(lista *l){
	return (*l).tam==0;
}

void Insere_frente(lista *l, char *str, int cont){
	celula *cel = (celula *) malloc(sizeof(celula));
	strncpy((*cel).caracteres, str, 30);
	(*cel).prox=(*cel).anter=NULL;
	(*cel).id = cont; 

	if(Lista_vazia(l)){
		(*l).inicio = (*l).fim = cel;
		(*l).inicio->prox = (*l).fim;
		(*l).fim->anter = (*l).inicio;

	}else{
		(*cel).anter = (*l).fim;
		(*l).fim->prox = cel;
		(*l).fim = cel;
	}
	(*l).tam++;
}

void Insere_atras(lista *l, char *str, int cont){
	celula *cel = (celula *) malloc(sizeof(celula));
	strncpy((*cel).caracteres, str, 30);
	(*cel).prox=(*cel).anter=NULL;
	(*cel).id = cont;

	if(Lista_vazia(l)){
		(*l).inicio = (*l).fim = cel;
		(*l).inicio->prox = (*l).fim;
		(*l).fim->anter = (*l).inicio;
	}else{
		(*cel).prox = (*l).inicio;
		(*l).inicio->anter = cel;
		(*l).inicio = cel;
	}
	(*l).tam++;
}

void Remove_frente(lista *l){
	if(Lista_vazia(l))
		cout<<"Lista vazia"<<endl;
	else if((*l).tam==1){
		(*l).fim = (*l).inicio =NULL;
		(*l).tam--;
	}
	else{
		celula *aux = (*l).fim->anter;
		(*l).fim->anter->prox = NULL;
		free((*l).fim);
		(*l).fim = aux;
		(*l).tam--;
	}
}

void Remove_atras(lista *l){
	if(Lista_vazia(l))
		cout<<"Lista vazia"<<endl;
	else if((*l).tam==1){
		(*l).fim = (*l).inicio =NULL;
		(*l).tam--;
	}
	else{
		celula *aux = (*l).inicio->prox;
		(*l).inicio->prox->anter = NULL;
		free((*l).inicio);
		(*l).inicio = aux;
		(*l).tam--;
	}
}

void Remove_esquerda(lista *l, celula *cel){
	if(Lista_vazia(l))
		cout<<"Lista vazia"<<endl;
	else
		if((*cel).anter!=NULL){
			celula *c = (*cel).anter;
			(*c).anter->prox = cel;
			(*cel).anter = (*c).anter;
			free((*cel).anter);
			(*l).tam--;
		}
}

void Remove_direita(lista *l, celula *cel){
	if(Lista_vazia(l))
		cout<<"Lista vazia"<<endl;
	else
		if((*cel).prox!=NULL){
			celula *c = (*cel).prox;
			(*c).prox->anter = cel;
			(*cel).prox = (*c).prox;
			free((*cel).prox);
			(*l).tam--;
		}
}

void Tamanho(lista *l){
	if(!Lista_vazia(l))
		cout<<(*l).tam<<endl;
	else
		cout<<"0"<<endl;
}

void Printa_lista(lista *l){
	if(Lista_vazia(l))
		cout<<"Lista vazia"<<endl;
	else{		
		celula *cel = (*l).fim;
		for(int i=0; i<(*l).tam; i++){
			cout<<(*cel).caracteres<<endl;
			cel = (*cel).anter;
		}
	}
}

void Pesquisa(lista *l, char * str, int val){
	celula *cel;
	if(val==1)
		cel = (*l).inicio;
	else
		cel = (*l).fim;
	for(int i=0; i<(*l).tam; i++){
		if(!strcmp((*cel).caracteres, str)){
			cout<<"Encontrado no codigo "<<(*cel).id<<endl;
			return;
		}
		if(val==1)
			cel = (*cel).prox;
		else
			cel = (*cel).anter;
	}
	cout<<"Nao Encontrado"<<endl;		
}

void Esvazia_lista(lista *l){
	while(!Lista_vazia(l))
		Remove_atras(l);
}

int main(){
	char ch, cha[30];
	int cont = 1;
	lista l;
	l.fim = l.inicio =NULL;
	l.tam = 0;
	while(!cin.eof()){
		cin>>ch;
		switch(ch){
			case 'E':
				cin>>cha;
				Insere_atras(&l, cha, cont);
				cont++;
				break;
			case 'D':
				cin>>cha;
				Insere_frente(&l, cha, cont);
				cont++;
				break;
			case 'e':
				Remove_atras(&l);
				break;
			case 'd':
				Remove_frente(&l);
				break;
			case 'P':
				cin>>cha;
				Pesquisa(&l, cha, 1);
				break;
			case 'Q':
				cin>>cha;
				Pesquisa(&l, cha, 0);
				break;
			case 'I':
				Printa_lista(&l);
				break;
			case 'T':
				Tamanho(&l);
				break;
			case 'S':
				return 0;
		}
	}
	return 0;
}