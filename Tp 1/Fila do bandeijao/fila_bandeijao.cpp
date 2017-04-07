#include <iostream>
#include <limits>

using namespace std;

void ordena (int * vetor, int tam){
	for(int i=0; i<tam-1; i++)
		for(int j=i+1; j<tam; j++)
			if(vetor[j]<vetor[i]){
				int aux = vetor[i];
				vetor[i]= vetor[j];
				vetor[j]=aux ;
			}
}

int soma (int i, int j, int * peso, int tam, int grupos){
	int soma = 0;
	int groups = 0;
	for(int aux = 0; aux<tam; aux++){
		cout<<aux<<"\n";
		if(aux==i){
			soma+=peso[j]-peso[i];
			aux=j;
			groups++;
		}
		else{
			if(groups==grupos-1){
				soma += peso[tam-1] - peso[aux];
				aux=tam-1;
			}
			else{
				soma += peso[aux];
				groups++;
			}
		}
	}
	return soma;
}

int main(){
	int pessoas, grupos;
	int peso[1000000];
	while(!cin.eof()){
		cin>>pessoas;
		cin>>grupos;
		for(int i=0; i<pessoas-1; i++)
			cin>>peso[i];
		int tam = pessoas-1;
		int min = numeric_limits<int>::max();
		ordena(peso, tam);
		for(int i=0; i<grupos; i++){
			for(int j=i+1; tam-((j-i))<= grupos; j++){
				int auxmin = soma(i, j, peso, tam, grupos);
				if(min>auxmin)
					min = auxmin;
			}
		}
		cout<<"Minimo = "<< min <<"\n";
	}
	return 0;
}