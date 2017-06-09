#include <iostream>
#include <chrono>
#include <random>
#include <string>

//#define TAM 1000
#define RAND 20000

typedef int tipo;

using namespace std;
using namespace std::chrono;

void printa(int *vetor, int e, int d){
		for(int i=e; i<=d; i++){
			if(i==d){
				cout<<vetor[i]<<endl;
				break;
			}
			cout<<vetor[i]<<", ";
		}
	}

void insertionV(int *vetor, int tam){
	for(int i=1; i<tam; i++){
		int aux=i-1, aux2 = vetor[i];
		while(aux2<vetor[aux] && aux>=0){
			vetor[aux+1] = vetor[aux];
			aux--;
		}
	vetor[aux+1]=aux2;
	}
}

class Tempo{
public:
	double inicio, fim;

	Tempo(){

	}

	void inicia(){
		inicio = high_resolution_clock::now().time_since_epoch().count();
	}

	void finaliza(string s, int TAM){
		fim = high_resolution_clock::now().time_since_epoch().count();
		cout<<s<<","<<TAM<<","<<(fim-inicio)/1000000<<endl;
	}

};

class Ordena{
public:
	tipo *vetor;
	Tempo tempo;
	int TAM;

	Ordena(int size){
		mt19937 semente;
		uniform_int_distribution<tipo> unif_int_d(0, RAND);
		semente.seed(high_resolution_clock::now().time_since_epoch().count());
		TAM = size;
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

	void printa(int e, int d){
		for(int i=e; i<=d; i++){
			if(i==d){
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

	void quickSort(int e, int d){
		int i=e, j=d;
		tipo pivo = vetor[(e + d)/2];
		while(i<=j){
			while(vetor[i]<pivo)
				i++;
			while(vetor[j]>pivo)
				j--;
			if(i<=j){
				int aux = vetor[j];
				vetor[j] = vetor[i];
				vetor[i] = aux;
				i++; j--;
			}
		}
	
		if(e<j)
			quickSort(e, j);
		if(i<d)
			quickSort(i, d);
	}

	void insertion(int e, int d){
		for(int i=e; i<=d; i++){
			int aux=i-1, aux2 = vetor[i];
			while(aux2<vetor[aux] && aux>=0){
				vetor[aux+1] = vetor[aux];
				aux--;
			}
		vetor[aux+1]=aux2;
		}
	}

	void insertion(){
		for(int i=1; i<TAM; i++){
			int aux=i-1, aux2 = vetor[i];
			while(aux2<vetor[aux] && aux>=0){
				vetor[aux+1] = vetor[aux];
				aux--;
			}
		vetor[aux+1]=aux2;
		}
	}

	void quickSortMediana(int e, int d){
		int i=e, j=d, meio = (e + d)/2, pivo;
		tipo vec[3];
		vec[0] = vetor[e]; vec[1] = vetor[d]; vec[2] = vetor[meio];
		insertionV(vec, 3);
		pivo = vec[1];

		while(i<=j){
			while(vetor[i]<pivo)
				i++;
			while(vetor[j]>pivo)
				j--;
			if(i<=j){
				int aux = vetor[j];
				vetor[j] = vetor[i];
				vetor[i] = aux;
				i++; j--;
			}
		}
		if(e<j)
			quickSort(e, j);
		if(i<d)
			quickSort(i, d);
	}

	void quickSortInsertion(int e, int d){
		if(d-e < 50)
			insertion(e+1, d);
		else{
			int i=e, j=d;
			tipo pivo = vetor[(e + d)/2];
			while(i<j){
				while(vetor[i]<pivo && i<TAM)
					i++;
				while(vetor[j]>pivo && j>=0)
					j--;
				if(i<j){
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
	}

	void shellSort(){
		int passo;
		for(passo = TAM/2; passo>0; passo=passo/2)
			for(int i=0; i<TAM; i+=passo){
				if(i+passo>=TAM)
					break;
				else if(vetor[i] > vetor[i+passo]){
					int aux = vetor[i];
					vetor[i] = vetor[i+passo];
					vetor[i+passo] = aux;
					aux = i-passo;
					while(aux>=0){
						if(vetor[aux]> vetor[aux+passo]){
							int aux2 = vetor[aux];
							vetor[aux] = vetor[aux+passo];
							vetor[aux+passo] = aux2;
						}
						aux -=passo;
					}
				}
			}
	}

	void confere(){
		for(int i=0; i<TAM-1; i++){
			if(vetor[i]>vetor[i+1]){
				cout<<"Não ordenado :(\n";
				exit(-1);
			}
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