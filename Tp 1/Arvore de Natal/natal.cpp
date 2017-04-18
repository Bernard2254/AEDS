/* ALUNOS:
∗ 201612040187: Bernard Menezes Moreira da Costa
∗ 201612040233: Thiago Figueiredo Costa
∗
∗ PROBLEMA: 2026 − Árvore de Natal
∗
∗ PARADIGMA: Guloso
∗
∗ DESCRICAO DA SOLUCAO: 
Assume que o maior valor de enfeites a serem colocados é o do pacote que possui o maior numero de enfeites, sava 
na variável soma1. Ordena vetor de acordo com a quantidade de enfeites (do maior para o menor), soma o máximo de 
elementos possíveisvsem estourar o limite de peso e salva na variável soma. Ordena os dados de acordo com os pesos
(do menor para o maior), soma o maior numero de enfeites possíveis sem estourar o limite de peso e salva em soma2.
Compara qual variável tem o maior valor, soma1, soma ou soma2, a resposta será o maior valor entre os três.
∗
∗ ORDEM DE COMPLEXIDADE: O(n²)
*/
#include <iostream>
#include <math.h>

using namespace std;

void ordena(int * vec, int tamanho){
	for(int i=1; i<tamanho; i=i+2)
		for(int j=1; j<tamanho; j=j+2)
			if(vec[j]>vec[i]){
				int aux = vec[i];
				vec[i]=vec[j];
				vec[j]=aux;
				aux = vec[i-1];
				vec[i-1]=vec[j-1];
				vec[j-1]=aux;
			}
}

void ordena2(int * vec, int tamanho){
	for(int i=0; i<tamanho; i=i+2)
		for(int j=0; j<tamanho; j=j+2)
			if(vec[j]<vec[i]){
				int aux = vec[i];
				vec[i]=vec[j];
				vec[j]=aux;
				aux = vec[i+1];
				vec[i+1]=vec[j+1];
				vec[j+1]=aux;
			}
}
int fuction(int *vec, int P, int W){
	int soma=0;
	int aglo=0;
	for(int i=0; i<P*2; i=i+2)
		for(int j=i+2; j<P*2; j=j+2){
			soma=vec[i];
			aglo=vec[i+1];
			while(aglo+vec[j+1]<=W){
				soma+=vec[j];
				aglo+=vec[j+1];
				j=j+2;
				if(aglo+vec[j+1]>W)
					return soma;
			}
			
		}
	return 0;
}

int main(){
	int G, P, W, acumula=0, vec[200], saida, i, soma, saida2, saida1=-1;
	cin>>G;
	while(acumula<G){
		cout<<"Galho "<<++acumula<<":"<<endl;
		cin>>P;
		cin>>W;
		for(i=0; i<P*2; i++)
			cin>>vec[i];
		ordena(vec, P*2);

		soma=0;
		saida=0;
		for(i=0; i<P*2 && soma<W; i=i+2){
			if(vec[i+1]+soma<=W){
				saida+=vec[i];
				soma+=vec[i+1];
			}
		}
		ordena2(vec, P*2);
		if(vec[1]<=W)
			saida1=vec[0];
		soma=0;
		saida2=fuction(vec, P, W);
		if(saida1>saida)
			saida=saida1;
		if(saida2>saida)
			saida=saida2;
		cout<<"Numero total de enfeites: "<<saida<<"\n\n";
	}
	return 0;
}
