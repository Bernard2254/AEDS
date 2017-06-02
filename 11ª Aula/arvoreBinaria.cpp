#include <iostream>
#include <string>

using namespace std;

struct registro{
	int id;
	string chave;
	registro * maior;
	registro * menor;
};

void balanceamento(registro *R){

}

void insere(int id, string chave, registro *R){
	registro *aux = R;
	registro *neww = (registro *)malloc(sizeof(registro));
	neww->id = id;
	cout<<"oi\n";
	neww->maior = neww->menor = NULL;
	cout<<"oi\n";
	neww->chave = chave;
	if(R==NULL)
		R = neww;
	else{
		while((*aux).maior!=NULL)
			aux = (*aux).maior;
		(*aux).maior = neww;
	}
	//balanceamento(R);
}

void printa(registro *R){
	if(R!=NULL){
		printa((*R).menor);
		cout<<R->chave<<" -> "<<R->id<<endl;
		printa((*R).maior);
	}
}

void pesquisa(registro *R, string s){
	if((*R).chave == s)
		cout<<"Achado!! Valor = "<<(*R).id<<endl;
	else{
		if((*R).maior != NULL)
			pesquisa((*R).maior, s);
		if((*R).menor != NULL)
			pesquisa((*R).menor, s); 
	}
}

int main(){
	registro *inicio = NULL;
	insere(1, "teste1", inicio);
	insere(2, "teste2", inicio);
	insere(3, "teste3", inicio);
	insere(4, "teste4", inicio);
	printa(inicio);
	return 0;
}