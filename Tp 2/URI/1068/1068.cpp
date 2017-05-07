#include <iostream>
#include <string.h>

using namespace std;

bool jump=false;

struct celula
{
	int valor;
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

void Empilha(pilha *p, int num){
	celula *cel = (celula *) malloc(sizeof(celula));
	(*cel).valor=num;
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
	if(Pilha_vazia(p)){
		cout<<"incorrect"<<endl;
		jump=true;
	}
	else{
		celula *aux = (*p).fim->prox;
		free((*p).fim);
		(*p).fim = aux;
	}
}

int Tamanho(pilha *p){
	if(Pilha_vazia(p))
		return 0;
	else
		return (*p).fim->id;
}

bool Confere(pilha *p){
	return Pilha_vazia(p);
}

int main(){
	string cha;
	char ch;
	pilha p;
	p.fim = NULL;
	while(cin>>cha){
		for(int i=0; i<cha.size() && jump==false; i++){
			ch = cha[i];
			if(ch == '(')
				Empilha(&p, (int)ch);
			else if(ch == ')'){
				Desempilha(&p);
				if(jump)
					break;
			}
		}
		if(!jump){
			if(Confere(&p))
				cout<<"correct"<<endl;
			else
				cout<<"incorrect"<<endl;
		}
		p.fim= NULL;
		jump = false;
	}

	return 0;
}