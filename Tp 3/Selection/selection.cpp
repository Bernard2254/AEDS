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

	void selection(int inicio){
		int num = vetor[inicio], index = inicio;
		for(int i=inicio+1; i<TAM; i++){
			if(vetor[i]<num){
				num = vetor[i];
				index = i;
			}
		}
		vetor[index] = vetor[inicio];
		vetor[inicio] = num;
		if(inicio!=TAM-2)
			selection(inicio+1);
	}
};

int main(){
	Ordena teste;
	teste.printa();
	teste.selection(0);
	teste.printa();

	return 0;
}