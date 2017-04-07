#include <iostream>
#include <limits>

using namespace std;

int ordena (int * vetor, int tam){
	tam++;
	int vec [1000000];
	vec[0]=0;
	for(int i =1; i<tam; i++){
			vec[i]=vetor[i-1];
	}
	vetor=vec;
	for(int i=0; i<tam-1; i++){
		for(int j=i+1; j<tam; j++){
			if(vetor[j]<vetor[i]){
				int aux = vetor[i];
				vetor[i]= vetor[j];
				vetor[j]=aux ;
			}
		}
	}
	for(int i =0; i<tam; i++)
		cout<<vetor[i]<< " ";
	return tam;
}

int soma (int i, int j, int * peso, int tam, int grupos){
	int soma = 0;
	int groups = 0;
	//cout<<"j = "<<j<<endl;
	for(int aux = 0; aux<tam; aux++){
		//cout<<aux<<"\n";
		if(tam-(j-i))
		if(aux==i){
			soma+= peso[j] - peso[i];
			groups++;
		}
		else{
			if(groups==grupos-1){
				soma += peso[tam-2] - peso[aux];
				aux=tam-1;
			}
			else{
				soma += 0;
				groups++;
			}
		}
		cout<<"OLHA = "<< soma<<endl;
	}
	return soma;
}

int main(){
	int pessoas, grupos;
	int peso[1000000];
	while(!cin.eof()){
		cin>>pessoas;
		cin>>grupos;
		for(int i=0; i<pessoas-1; i++)
			cin>>peso[i];
		int tam = pessoas-1;
		int min = numeric_limits<int>::max();
		tam = ordena(peso, tam);
		cout<<"tam = "<<tam<<"\n";
		for(int i=0; i<grupos; i++){
			for(int j=i+1; grupos-((j-i)+1)!= 0 ; j++){
				int auxmin = soma(i, j, peso, tam, grupos);
				cout<<"i = "<<i<<" "<<"j = "<<j<<endl;
				cout<<"Soma ["<<i<<"] = "<< auxmin<<endl;
				if(min>auxmin)
					min = auxmin;
			}
		}
		cout<<"Minimo = "<< min <<"\n";
	}
	return 0;
}