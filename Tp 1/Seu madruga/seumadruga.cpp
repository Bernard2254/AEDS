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
