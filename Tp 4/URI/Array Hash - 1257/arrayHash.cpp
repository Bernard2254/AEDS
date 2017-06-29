/* ALUNO: 201612040187 - Bernard Menezes 
*  PROBLEMA: 1257 − Array Hash 
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	int N, subN;
	cin>>N;
	//cout<<N<<endl;
	for(int i =0; i<N; i++){
		cin>>subN;
		int saida = 0;
		for(int k=0; k<subN; k++){
			string s;
			cin>>s;
			for(int j=0; j<s.size(); j++){
				saida += ((int)s.at(j) - 65) + k + j;
			}
		}
		cout<<saida<<endl;
	}
}