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

void Empilha(pilha *p, int num, char *str){
	celula *cel = (celula *) malloc(sizeof(celula));
	(*cel).valor=num;
	strncpy((*cel).caracteres, str, 30);
	(*cel).prox = NULL;
	if((*p).fim==NULL){
		(*cel).id=1;
		(*p).fim=cel;			
	}
	else{
		(*cel).id = (*p).fim->id + 1;
		(*cel).prox = (*p).fim;
		(*p).fim = cel;
	}
}

int main(){
	pilha p;
	p.fim=NULL;
	cout<<"oi\n";
	
	Empilha(&p, 10, (char *)"os");
	Empilha(&p, 12, (char *)"os");
	cout<<"Olha = "<<p.fim->valor<<endl;
	return 0;
}