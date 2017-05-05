#include <iostream>

using namespace std;

struct fila
{
	int *vetor;
	int inicio;
	int final;
	int tam_max;
};

void Cria_fila(fila *f, int tam){
	int *vec = (int *) calloc(0,sizeof(int)*tam);
	(*f).vetor   = vec;
	(*f).inicio  = (*f).final = 0;
	(*f).tam_max = tam;
}

void Insere(fila *f, int num){
	if((*f).final - (*f).inicio == (*f).tam_max)
		cout<<"Fila cheia\n";
	else{
		(*f).vetor[(*f).final] = num;
		(*f).final++;
	}
}

bool Fila_vazia(fila *f){
	if((*f).final - (*f).inicio == 0)
		return true;
	return false;
}

void Printa_frente(fila *f){
	if((*f).final - (*f).inicio == 0)
		cout<<"Fila vazia\n";
	else
		cout<<(*f).vetor[(*f).inicio]<<endl;
}


void Desemfilera(fila *f){
	if(Fila_vazia(f))
		cout<<"Fila vazia\n";
	else
		(*f).inicio++;
}

void Tamanho(fila *f){
	cout<<(*f).final - (*f).inicio<<endl;
}

void Esvazia(fila *f){
	(*f).final=(*f).inicio = 0;
}

int main(){
	fila f;
	int N, num;
	char ch;
	cin>>N;
	Cria_fila(&f, N);
	while(!cin.eof()){
		cin>>ch;
		//cout<<"Olha: "<<ch<<endl;
		switch(ch){
			case 'E':
				cin>>num;
				Insere(&f, num);
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