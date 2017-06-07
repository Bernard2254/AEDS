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

	void insertion(){
		for(int i=1; i<TAM; i++){
			int aux=i-1, aux2 = vetor[i];
			while(aux2<vetor[aux]){
				vetor[aux+1] = vetor[aux];
				aux--;
			}
		vetor[aux+1]=aux2;
		}
		printa();
	}
};

int main(){
	Ordena teste;
	teste.printa();
	teste.insertion();
	return 0;
}