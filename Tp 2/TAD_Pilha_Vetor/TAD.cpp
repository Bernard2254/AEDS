#include <iostream>

using namespace std;

struct pilha
{
	int *vetor;
	int inicio;
	int final;
	int tam_max;
};

void Cria_pilha(pilha *p, int tam){
	int *vec = (int *) calloc(0,sizeof(int)*tam);
	(*p).vetor   = vec;
	(*p).inicio  = (*p).final = 0;
	(*p).tam_max = tam;
}

void Empilha(pilha *p, int num){
	if((*p).final - (*p).inicio == (*p).tam_max)
		cout<<"Pilha cheia\n";
	else{
		(*p).vetor[(*p).final] = num;
		(*p).final++;
	}
}

bool Pilha_vazia(pilha *p){
	if((*p).final - (*p).inicio == 0)
		return true;
	return false;
}

void Printa_topo(pilha *p){
	if((*p).final - (*p).inicio == 0)
		cout<<"Pilha vazia\n";
	else
		cout<<(*p).vetor[(*p).final-1]<<endl;
}


void Desempilha(pilha *p){
	if(Pilha_vazia(p))
		cout<<"Pilha vazia\n";
	else
		(*p).final--;
}

void Tamanho(pilha *p){
	cout<<(*p).final - (*p).inicio<<endl;
}

void Esvazia(pilha *p){
	(*p).final=(*p).inicio;
}

int main(){
	pilha p;
	int N, num;
	char ch;
	cin>>N;
	Cria_pilha(&p, N);
	while(!cin.eof()){
		cin>>ch;
		//cout<<"Olha: "<<ch<<endl;
		switch(ch){
			case 'E':
				cin>>num;
				Empilha(&p, num);
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