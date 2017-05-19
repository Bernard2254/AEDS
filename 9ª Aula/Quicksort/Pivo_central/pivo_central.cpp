#include <iostream>
#include <time.h> 

#define SIZE 100

using namespace std;

typedef int type;

void Printa(type *v){
	for(int i=0; i<SIZE; i++)
		cout<<"v["<<i<<"] = "<<v[i]<<endl;
}

void Preenche_vetor(type *v){
	for(int i=0; i<SIZE; i++)
		v[i] = (type)rand()%1000;
	Printa(v);
	cout<<"\n";
}

void Particiona(type *v, int *esq, int *dir, int *i, int *j){
	*i = *esq;
	*j = *dir;
	type aux;
	int pivo = v[*esq + (*dir - *esq)/2];
	do{
		while(v[*i]<pivo)
			*i=*i+1;
		while(v[*j]>pivo)
			*j=*j-1;
		if(*i<=*j){
			aux = v[*i];
			v[*i] = v[*j];
			v[*j] = aux;
			*i=*i+1; *j=*j-1;
		}
	}while(*i<=*j);
}

void Ordena(type *v, int *esq, int *dir){
	int i, j;
	Particiona(v, esq, dir, &i, &j);
	if(*esq<j)
		Ordena(v, esq, &j);
	if(*dir>i)
		Ordena(v, &i, dir);
}

int main(){
	int inicio = 0, fim = SIZE-1;
	srand(time(0));
	type *vetor = (type *)malloc(sizeof(type)*SIZE);
	Preenche_vetor(vetor);
	Ordena(vetor, &inicio, &fim);
	Printa(vetor);
	return 0;
}