/* ALUNOS: ∗ 201612040187: Bernard Menezes Moreira da Costa
∗ 201612040233: Thiago Figueiredo Costa
∗
∗ PROBLEMA: 1286 - Motoboy
∗
∗ PARADIGMA: Programacao dinamica
∗
∗ DESCRICAO DA SOLUCAO:
	define o caso base como zero
	e vai percorrendo a tabela (quantidade de pacotes X capacidade)
	o peso é definido pelas colunas, se tiver como colocar mais alguma coisa na caixinha do motoboy ele pega o caso com mais valor
	se nao ele define o caso anterior
	no final o valor é o ultimo elemento da tabela
∗
∗ ORDEM DE COMPLEXIDADE: O(n*capacidade) */
#include <iostream>
#define PRINT 0
using namespace std;

int main(){
	int n,max;
	while(cin>>n,n){
		cin>>max;
		int value[n];
		int weight[n]; 								
		for(int i=0;i<n;i++){
			int a,b;
			cin>>value[i];
			cin>>weight[i]; 						
		}
		int dinamica[++n][++max];
		for(int i=0;i<n;i++){
			for(int j=0;j<max;j++){
				if(i==0||j==0){
				 dinamica[i][j]=0;
				}else{
					if(weight[i-1]<=j){
						dinamica[i][j]=value[i-1]+dinamica[i-1][j-weight[i-1]]>dinamica[i-1][j]?value[i-1]+dinamica[i-1][j-weight[i-1]]:dinamica[i-1][j];
					}else{
						dinamica[i][j]=dinamica[i-1][j];
					}
				}
			}
		}
		if(PRINT)			for(int i=0;i<n;i++){for(int j=0;j<max;j++)cout<<dinamica[i][j]<<" ";cout<<endl;if(i+1==n){cout<<dinamica[n-1][max-1]<<" min.\n";cout<<endl;}}else
		cout<<dinamica[--n][--max]<<" min.\n";
	}
	return 0;
}