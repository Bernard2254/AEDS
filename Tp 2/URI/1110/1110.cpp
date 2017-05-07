#include <iostream>
#include <string.h>

using namespace std;

struct celula
{
	int id;
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

void Insere_frente(lista *l, int cont){
	celula *cel = (celula *) malloc(sizeof(celula));
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

void Insere_atras(lista *l, int cont){
	celula *cel = (celula *) malloc(sizeof(celula));
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

int Tamanho(lista *l){
	if(!Lista_vazia(l))
		return (*l).tam;
	else
		return 0;
}

void Printa_lista(lista *l){
	if(Lista_vazia(l))
		cout<<"Lista vazia"<<endl;
	else{		
		celula *cel = (*l).fim;
		for(int i=0; i<(*l).tam; i++){
			cout<<(*cel).id<<endl;
			cel = (*cel).anter;
		}
	}
}

void Esvazia_lista(lista *l){
	while(!Lista_vazia(l))
		Remove_atras(l);
}

int main(){
	int N;
	lista l;
	l.fim = l.inicio =NULL;
	l.tam = 0;
	while(!cin.eof()){
		cin>>N;
		if(N>=2){
			for(int i=1; i<N+1; i++)
				Insere_frente(&l, i);
			cout<<"Discarded cards: ";
			while(Tamanho(&l)!=1){
				if(Tamanho(&l)==2)
					cout<<l.inicio->id;
				else
					cout<<l.inicio->id<<", ";
				Remove_atras(&l);
				Insere_frente(&l, l.inicio->id);
				Remove_atras(&l);
			}
			cout<<"\nRemaining card: "<<l.inicio->id<<endl;
			Esvazia_lista(&l);
		}
	}

	return 0;
}