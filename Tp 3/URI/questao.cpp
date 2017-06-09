#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


typedef struct t{
	string nome;
	int notas[12];
	int soma;
}Estudante;

void printa(int esq, int d, Estudante *e){
	for(int i=d, j=1; i>=0; i--, j++)
		cout<<j<<" "<< e[i].soma <<" "<<e[i].nome<<endl;
}

void quick(Estudante *e, int esq, int d){
	int i=esq, j=d, pivo = e[(esq+d)/2].soma;
	while(i<=j){
		while(e[i].soma < pivo)
			i++;
		while(e[j].soma > pivo)
			j--;
		if(i<=j){
			Estudante aux = e[i];
			e[i] = e[j];
			e[j] = aux;
			j--; i++;
		}
	}
	if(esq<j)
		quick(e, esq, j);
	if(d>i)
		quick(e, i, d);
}

 void garante(Estudante *e, int num){
	for(int i=0; i+1<num; i++)
		for(int j=i+1; j<num; j++){
			if(e[i].soma == e[j].soma)
				if(e[i].nome<e[j].nome){
					Estudante aux = e[i];
					e[i] = e[j];
					e[j] = aux;
				}
		}
}


int main(int argc, char** argv){
	int num, l = 1; string s;
	while(1){
		cin>>num;
		if(num==0)
			return 0;
		cout<<"Teste "<<l<<endl;
		Estudante vetor[num];
		for(int i=0; i<num; i++){
			cin>>s;
			Estudante e;
			for(int j = 0; j<12; j++)
				cin>>e.notas[j];
			e.nome=s; e.soma=0;
			vetor[i] = e;
		}
		int maior, menor, soma;
		for(int j=0; j<num; j++){
			maior=vetor[j].notas[0]; menor=vetor[j].notas[0];  soma=0;
			for(int i=0; i<12; i++){
				if(vetor[j].notas[i]>maior)
					maior = vetor[j].notas[i];
				else if(vetor[j].notas[i]<menor)
					menor = vetor[j].notas[i];
				soma+=vetor[j].notas[i];
			}
			vetor[j].soma = soma-maior-menor;
		}

		quick(vetor, 0, num-1);
		garante(vetor, num);
		printa(0, num-1,vetor);
		cout<<"\n";
	}
	
	return 0;
}