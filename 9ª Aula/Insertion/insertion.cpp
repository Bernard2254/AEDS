#include <iostream>
#include <time.h> 

#define SIZE 10

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

void Insertion(type *v){
	for(int i=1; i<SIZE; i++){
		int aux=i-1, aux2 = v[i];
		while(aux2<v[aux]){
			v[aux+1] = v[aux];
			aux--;
		}
		v[aux+1]=aux2;
		
	}
}

int main(){
	srand(time(0));
	type *vetor = (type *)malloc(sizeof(type)*SIZE);
	Preenche_vetor(vetor);
	Insertion(vetor);
	Printa(vetor);
	return 0;
}