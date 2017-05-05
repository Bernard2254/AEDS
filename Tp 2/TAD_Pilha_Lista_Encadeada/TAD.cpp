#include <iostream>
#include <string.h>

using namespace std;

struct celula
{
	int valor;
	char caracteres[30];
	celula *prox;
	int id;
};

struct pilha
{
	celula *fim;
};

bool Pilha_vazia(pilha *p){
	return (*p).fim==NULL;
}

void Empilha(pilha *p, int num, char *str){
	celula *cel = (celula *) malloc(sizeof(celula));
	(*cel).valor=num;
	strncpy((*cel).caracteres, str, 30);
	(*cel).prox = NULL;
	if(Pilha_vazia(p)){
		(*cel).id=1;
		(*p).fim=cel;			
	}
	else{
		(*cel).id = (*p).fim->id + 1;
		(*cel).prox = (*p).fim;
		(*p).fim = cel;
	}
}

void Desempilha(pilha *p){
	if(Pilha_vazia(p))
		cout<<"Pilha vazia"<<endl;
	else{
		celula *aux = (*p).fim->prox;
		free((*p).fim);
		(*p).fim = aux;
	}
}

void Printa_topo(pilha *p){
	if(Pilha_vazia(p))
		cout<<"Pilha vazia"<<endl;
	else{
		cout<<(*p).fim->valor<<" "<<(*p).fim->caracteres<<endl;
	}
}

void Tamanho(pilha *p){
	if(Pilha_vazia(p))
		cout<<"0"<<endl;
	else
		cout<<(*p).fim->id<<endl;
}

void Esvazia_pilha(pilha *p){
	int t = (*p).fim->id;
	for(int i=0; i<t; i++)
		Desempilha(p);
}

int main(){
	int num;
	char cha[30], ch;
	pilha p;
	p.fim=NULL;

	while(!cin.eof()){
		cin>>ch;
		switch(ch){
			case 'E':
				cin>>num;
				cin>>cha;
				Empilha(&p, num, cha);
				break;
			case 'D':
				Desempilha(&p);
				break;
			case 'T':
				Tamanho(&p);
				break;
			case 'I':
				Printa_topo(&p);
				break;
			case 'S':
				return 0;
		}
	}
	return 0;
}