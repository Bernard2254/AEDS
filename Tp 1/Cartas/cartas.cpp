/* ALUNOS: ∗ 201612040187: Bernard Menezes Moreira da Costa
∗ 201612040233: Thiago Figueiredo Costa
∗
∗ PROBLEMA: 1104 - Exchanging Cards
∗
∗ PARADIGMA: sem paradigma
∗
∗ DESCRICAO DA SOLUCAO:
ve quantas cartas unicas diferentes entre as duas pessoas e retorna esse valor

∗
∗ ORDEM DE COMPLEXIDADE: O(n2) */
#include <iostream>

using namespace std;

int main(){
int a,b,t;
	while(true){
		cin>>a>>b;
		if(a==0&&b==0) break;
		int cardsA[a]; int sizeA=0;
		int cardsB[b]; int sizeB=0;
		for(int i=0;i<a;i++){
			cin>>t;
			if(sizeA==0){
				cardsA[sizeA]=t;
				sizeA++;
			}else if(cardsA[sizeA-1]!=t){
				cardsA[sizeA]=t;
				sizeA++;
			}
		}
		for(int i=0;i<b;i++){
			cin>>t;
			if(sizeB==0){
				cardsB[sizeB]=t;
				sizeB++;
			}else if(cardsB[sizeB-1]!=t){
				cardsB[sizeB]=t;
				sizeB++;
			}
		}
		int count=0;
		if(sizeA<sizeB)
			count=sizeA;
		else 
			count=sizeB;
		for(int i=0;i<sizeA;i++)
			for(int j=0;j<sizeB;j++){
				if(cardsA[i]==cardsB[j])
					count--;
				if(cardsA[i]<=cardsB[j])
					break;
			}
		cout<<count<<endl;
}

    return 0;
}

