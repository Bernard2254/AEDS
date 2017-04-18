/* ALUNOS:
∗ 201612040187: Bernard Menezes Moreira da Costa
∗ 201612040233: Thiago Figueiredo Costa
∗
∗ PROBLEMA: 1912 − Ajude o Seu Madruga
∗
∗ PARADIGMA: Tentativa e erro usando balanceamento 
∗
∗ DESCRICAO DA SOLUCAO: 
Analisa-se se é possível solucionar o problema (se ele é válido)
-> Caso afirmativo: 
	*Solução já está pronta? 
	Exibe: :D.
	*Solução não está pronta?
	Tem como ponto de partida o meio da maior tira do problema. Calcula a area usando esse ponto como se fosse o de corte.
		+ Caso a area obtida seja maior que a procurada: aumenta o ponto de corte para a metade da distancia entre o topo da 
		maior tira e o ponto de corte atual;
		+ Caso a area obtida seja menor que a procurada: diminui o ponto de corte para a metade da distancia entre o ponto de
		corte atual e o ponto de corte anterior;
		+ Caso a area obtida seja a desejada (como foi pedido uma precisão de 4 casas decimais foi colocado uma condiçao para
		otimizar o código: se a diferenca entra a area obtida e a area desejada for menor que 0.0001, as consideraremos iguais):
		exibe na tela o ponto de corte.
-> Caso negativo:
	*Problema não tem solução: exibe: -.-
	*Se a area procurada ou o numero de tiras forem iguais a zero, não exibe nada

∗
∗ ORDEM DE COMPLEXIDADE: O(n) + (O(log(n)*O(n)))
*/
#include <iostream>
#include <math.h>

using namespace std;

int maximo=0;

int main(){
	double area, soma, A, N, altura[100000];
	while(!cin.eof()){
		soma=0;
		cin>>N;
		cin>>A;
		if(N!=0 && A!=0){
			for(int i=0; i<N; i++){
				cin>>altura[i];
				soma+=altura[i];
				if(altura[maximo]<altura[i])
					maximo=i;
			}
			if(soma==A)
				cout<<":D"<<endl;
			else if(soma<A)
				cout<<"-.-"<<endl;
			else{
				double alt=altura[maximo]/2;
				double ant=0;
				do{
					area=0;
					for(int i=0; i<N; i++)
						if(altura[i]>alt)
							area+=(altura[i]-alt);
					if(fabs(area-A)<0.0001){
						area=A;
					}
					else{
						if(area>A){
							ant=alt;
							alt+=(altura[maximo]-alt)/2;
						}
						else if(area<A)
							alt-=(alt-ant)/2;
					}
				}while(area!=A);
				cout.precision(4);
				cout<<fixed<<alt<<endl;
			}
		}
	}
	return 0;
}
