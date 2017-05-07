#include <iostream>
#include <string.h>

using namespace std;

struct celula
{
	int id;
	char valor;
	celula *prox;
};

struct pilha
{
	celula *fim;
};

bool Pilha_vazia(pilha &p){
	return p.fim==NULL;
}

void Empilha(pilha &p, int ch){
	celula *cel = (celula *) malloc(sizeof(celula));
	(*cel).valor = ch;
	(*cel).prox = NULL;
	if(Pilha_vazia(p)){
		(*cel).id=1;
		p.fim=cel;			
	}
	else{
		(*cel).id = p.fim->id + 1;
		(*cel).prox = p.fim;
		p.fim = cel;
	}
}

void Desempilha(pilha &p){
	if(Pilha_vazia(p))
		cout<<"Pilha vazia"<<endl;
	else{
		celula *aux = p.fim->prox;
		free(p.fim);
		p.fim = aux;
	}
}

int main(){
	int N, contador=0;
	string cha;
	pilha p;
	p.fim = NULL;
	cin>>N;
	while(contador!=N){
		cin>>cha;

		cout<<cha<<endl;
		contador++;
	}
	Empilha(p, 'x');
	
	return 0;
}