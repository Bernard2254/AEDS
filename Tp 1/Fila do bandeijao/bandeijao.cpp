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