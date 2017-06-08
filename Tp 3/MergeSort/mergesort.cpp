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

	void mergeSort(int esq, int dir){
		if(esq<dir){
			int meio = (dir+esq)/2;
			mergeSort(esq, meio);
			mergeSort(meio+1, dir);
			merge(esq, dir, meio);
		}
	}

	void merge(int esq, int dir, int meio){
		tipo *vec_final = (tipo*) malloc((dir-esq+1)*sizeof(tipo));

		int i = 0, aux_esq = esq, aux_dir = meio+1;

		while(aux_esq<=meio && aux_dir<=dir){
			if(vetor[aux_dir]<vetor[aux_esq]){
				vec_final[i] = vetor[aux_dir];
				aux_dir++;
			}
			else{
				vec_final[i] = vetor[aux_esq];
				aux_esq++;
			}
			i++;
		}

		if(aux_esq>meio)
			while(aux_dir<=dir)
				vec_final[i++] = vetor[aux_dir++];
		else
			while(aux_esq<=meio)
				vec_final[i++] = vetor[aux_esq++];

		for(i=esq; i<=dir; i++)
			vetor[i] = vec_final[i - esq];

		free(vec_final);
	}
};

int main(){
	Ordena teste;
	teste.printa();
	teste.mergeSort(0, TAM-1);
	teste.printa();

	return 0;
}