/* ALUNO: Bernard Menezes 
*  PROBLEMA: 1256 − Tabelas Hash 
*/

#include <iostream>

using namespace std;

class Cell{
	public:
		Cell *prox;
		int cont;

		Cell(){
			this->cont = 0;
			this->prox = NULL;
		}

		Cell(int cont){
			this->cont = cont;
			this->prox = NULL;
		}
};

class Hash{
	public:
		int mod;
		Cell *table;

		Hash(int mod){
			this->mod = mod;
			this->table = (Cell *)malloc(mod*sizeof(Cell));
			for(int i=0; i<mod; i++)
				table[i] = Cell();
		}

		void insert(int num){
			int index = num%mod;
			if(table[index].cont == 0){
				table[index] = Cell(num);
			}
			else{
				Cell *n = new Cell();
				n->cont = num;
				n->prox = NULL;
				if(table[index].prox != NULL){
					Cell *aux = table[index].prox;
					while(aux->prox)
						aux = aux->prox;
					aux->prox = n;
				}else
					table[index].prox = n;
			}
		}
};

void leHash(Hash h){
	for(int i=0; i<h.mod; i++){
		cout<<i;
		Cell aux = h.table[i];
		Cell *aux2;
		if(aux.cont != 0)
			cout<<" -> "<<aux.cont;
		aux2 = aux.prox;
		while(aux2){
			cout<<" -> "<<aux2->cont;
			aux2 = aux2->prox;
		}
		cout<<" -> \\";
		cout<<endl;
	}
}

int main(){
	int N;
	cin>>N;

	for(int k=0; k<N; k++){
		int tam, num;
		cin>>tam;
		cin>>num;
		Hash table = Hash(tam);
		int i;
		for(int j=0; j<num; j++){
			cin>>i;
			table.insert(i);
		}
		leHash(table);
		if(k!=N-1)
			cout<<endl;
	}
}