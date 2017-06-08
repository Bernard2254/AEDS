#include <iostream>
#include <chrono>
#include <random>

#define TAM 10

typedef int tipo;

using namespace std;
using namespace std::chrono;

class Ordena{
public:
	tipo *vetor;

	Ordena(){
		mt19937 semente;
		uniform_int_distribution<tipo> unif_int_d(0, 100);
		semente.seed(high_resolution_clock::now().time_since_epoch().count());

		vetor = (tipo *)malloc(sizeof(tipo) * TAM);
		for(int i=0; i<TAM; i++)
			vetor[i] = unif_int_d(semente);
	}

	void printa(){
		for(int i=0; i<TAM; i++){
			if(i==TAM-1){
				cout<<vetor[i]<<endl;
				break;
			}
			cout<<vetor[i]<<", ";
		}
	}

	void quickSort(int e, int d){
		int i=e, j=d;
		tipo pivo = vetor[(e + d)/2];
		while(i<=j){
			while(vetor[i]<pivo && i<TAM)
				i++;
			while(vetor[j]>pivo && j>=0)
				j--;
			if(i<=j){
				int aux = vetor[j];
				vetor[j] = vetor[i];
				vetor[i] = aux;
				i++; j--;
			}
		}
		
		if(j-e>1)
			quickSort(e, j);
		if(d-i>1)
			quickSort(i, d);
	}
		
};

int main(){
	Ordena teste;
	teste.printa();
	teste.quickSort(0, TAM-1);
	teste.printa();

	return 0;
}