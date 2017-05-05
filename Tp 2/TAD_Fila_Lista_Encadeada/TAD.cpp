#include <iostream>
#include <string.h>

using namespace std;

struct celula
{
	int inteiro;
	float decimal;
	celula *prox;
	int id;
};

struct fila
{
	celula *fim;
	celula *inicio;
};

bool Fila_vazia(fila *f){
	return (*f).inicio==NULL;
}

void Enfilera(fila *f, int num, float n){
	celula *cel = (celula *) malloc(sizeof(celula));
	(*cel).inteiro=num;
	(*cel).decimal = n;
	(*cel).prox = NULL;
	if(Fila_vazia(f)){
		(*cel).id=0;
		(*f).inicio=(*f).fim=cel;
		(*f).inicio->prox=(*f).fim;		
	}
	else{
		(*f).fim->prox= cel;
		(*cel).id = (*f).fim->id + 1;
		(*f).fim = cel;
	}
}

void Desemfilera(fila *f){
	if(Fila_vazia(f))
		cout<<"Fila vazia"<<endl;
	else{
		celula *aux = (*f).inicio->prox;
		free((*f).inicio);
		(*f).inicio = aux;
	}
}

void Printa_frente(fila *f){
	if(Fila_vazia(f))
		cout<<"Fila vazia"<<endl;
	else{
		cout<<(*f).inicio->inteiro<<" "<<(*f).inicio->decimal<<endl;
	}
}

void Tamanho(fila *f){
	if(Fila_vazia(f))
		cout<<"0"<<endl;
	else
		cout<<(*f).fim->id - (*f).inicio->id + 1<<endl;
}

void Esvazia_fila(fila *f){
	int t = (*f).fim->id;
	for(int i=0; i<t; i++)
		Desemfilera(f);
}

int main(){
	int num;
	float dec;
	char ch;
	fila f;
	f.fim=f.inicio=NULL;

	while(!cin.eof()){
		cin>>ch;
		switch(ch){
			case 'E':
				cin>>num;
				cin>>dec;
				Enfilera(&f, num, dec);
				break;
			case 'D':
				Desemfilera(&f);
				break;
			case 'T':
				Tamanho(&f);
				break;
			case 'I':
				Printa_frente(&f);
				break;
			case 'S':
				return 0;
		}
	}
	return 0;
}