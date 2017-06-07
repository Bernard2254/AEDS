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

	void mergesort(int esq, int dir){
		if(esq<dir){
			int meio = (dir+esq)/2;
			mergesort(esq, meio);
			mergesort(meio, dir);
			merge(esq, dir, meio);
		}
	}

	void merge(int esq, int dir, int meio){
		tipo *vec_final = (tipo*) malloc(sizeof(dir-esq+1));

		int i = 0, aux_dir = esq, aux_esq = meio;

		while(aux_dir<meio && aux_esq<=dir){
			if(vetor[aux_dir]<vetor[aux_esq])
				vec_final[i] = vetor[aux_dir];
			else
				vec_final[i] = vetor[aux_esq];
			i++;
		}

		if(aux_dir>=meio)
			while(aux_esq<=dir)
				vec_final[i++] = vetor[aux_esq];
		else
			while(aux_dir<meio)
				vec_final[i++] = vetor[aux_dir];

		for(i=0; i<TAM; i++)
			vetor[i] = vec_final[i - esq];

		free(vec_final);
	}
};

int main(){
	Ordena teste;
	teste.printa();
	teste.mergesort(0, TAM-1);
	return 0;
}