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

	void copiaVetor(tipo *vec, int size){
		free(vetor);
		vetor = (tipo *)malloc(sizeof(tipo) * size);
		for(int i=0; i<size; i++)
			vetor[i] = vec[i];

	}

	void Experimento(tipo *vec, int size){
		copiaVetor(vec, size);
		this->TAM = size;

		this->tempo.inicia();
			this->selection();
		this->tempo.finaliza("Selection", size);
		this->confere();

		copiaVetor(vec, size);

		this->tempo.inicia();
			this->quickSort(0, size-1);
		this->tempo.finaliza("Quick 1", size);
		this->confere();

		copiaVetor(vec, size);

		this->tempo.inicia();
			this->insertion();
		this->tempo.finaliza("Insertion", size);
		this->confere();

		copiaVetor(vec, size);

		this->tempo.inicia();
			this->quickSortMediana(0, size-1);
		this->tempo.finaliza("Quick 2", size);
		this->confere();

		copiaVetor(vec, size);

		this->tempo.inicia();
			this->quickSortInsertion(0, size-1);
		this->tempo.finaliza("Quick 3", size);
		this->confere();

		copiaVetor(vec, size);

		this->tempo.inicia();
			this->shellSort();
		this->tempo.finaliza("Shell", size);
		this->confere();

		copiaVetor(vec, size);

		this->tempo.inicia();
			this->mergeSort(0, size-1);
		this->tempo.finaliza("Merge", size);
		this->confere();
	}

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

	void selection(){
		int num, index, inicio;
		for(int j=0; j<TAM; j++){
			num = vetor[j];
			inicio=index=j;
			for(int i=j+1; i<TAM; i++){
				if(vetor[i]<num){
					num = vetor[i];
					index = i;
				}
			}
			vetor[index] = vetor[inicio];
			vetor[inicio] = num;
		}
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
				while(vetor[i]<pivo)
					i++;
				while(vetor[j]>pivo)
					j--;
				if(i<j){
					int aux = vetor[j];
					vetor[j] = vetor[i];
					vetor[i] = aux;
					i++; j--;
				}
			}
			
			if(e<j)
				quickSort(e, j);
			if(d>i)
				quickSort(i, d);
		}
	}

	void shellSort(){
		int passo=1;
		do {
			passo = 3*passo +1;
		}while(passo<TAM);
		for(passo = passo/3; passo>0; passo=passo/3){
			for(int i=0; i+passo<TAM; i++){
				int aux=i;
				while(aux>=0 && vetor[aux] > vetor[aux+passo]){
					int aux2 = vetor[aux];
					vetor[aux] = vetor[aux+passo];
					vetor[aux+passo] = aux2;
					aux-=passo;	
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