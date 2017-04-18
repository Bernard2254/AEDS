/* ALUNOS: ∗ 201612040187: Bernard Menezes Moreira da Costa
∗ 201612040233: Thiago Figueiredo Costa
∗
∗ PROBLEMA: 1524 - Cafeteria Queue
∗
∗ PARADIGMA: Guloso
∗
∗ DESCRICAO DA SOLUCAO:
enquanto lê a entrada salva a distancia entre elas em outro vetor.
percorre o vetor de distancias e vai pegando as menores distancias possiveis e 
somando a distancias que foram pegadas, a cada soma dessa um grupo é formado. 
quando são feitas junções sufientes para formar a quantidade de grupos desejada encerra
∗
∗ ORDEM DE COMPLEXIDADE: O(n2) */
#include <iostream>

using namespace std;

int main(){
	int n, grupos;
	while(cin>>n>>grupos,!cin.eof()){
		long peso[n],dist[n];
		peso[0]=dist[n-1]=0;
		for(int i=1; i<n; i++){
			cin>>peso[i];
			dist[i-1]=peso[i]-peso[i-1];
		}
		int i=-1,c=grupos;
		while(i++==666||c<n)
		for(int j=0;j<n-1;j++){
			if(dist[j]==i){
				dist[n-1]+=dist[j];
				if(++c>=n){
					cout<<dist[n-1]<<endl;
					break;
				}
			}
		}
	}
	return 0;
}