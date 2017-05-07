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