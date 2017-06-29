#include <iostream>
#include <string>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

#define NUMBER_OF_TESTS 3
#define EMPTY " "

class Cell{
	public:
		string cont;
		Cell *right = NULL;
		Cell *left = NULL;

		Cell(){
			cont = EMPTY;
		}

		Cell(string cont){
			cont = cont;
		}
};

void insertBinaryTree(Cell *table, Cell *inicio){
	if(table->cont <= inicio->cont)
		if(inicio->left)
			insertBinaryTree(table, inicio->left);
		else
			inicio->left = table;
	else
		if(inicio->right)
			insertBinaryTree(table, inicio->right);
		else
			inicio->right = table;
}

void leBinaryTree(Cell *table, int *i){;
	if(!table)
		return;
	leBinaryTree(table->left, i);
	*i = *i+1;
	cout<<"\t"<<*i<<" -> ";
	cout<<table->cont<<endl;
	leBinaryTree(table->right, i);
}

void writeTreeInVector(Cell *table, int *i, string cont, string *vec){;
	if(!table)
		return;
	writeTreeInVector(table->left, i, cont, vec);
	if(table->cont != cont){
		vec[*i] = table->cont;
		*i = *i+1;
	}
	writeTreeInVector(table->right, i, cont, vec);
}

class Hash{
	public:
		Cell *table;
		int mod, colision = 0;

		Hash(int mod){
			this->table = (Cell *)malloc(mod*sizeof(Cell));
			for(int i=0; i<mod; i++)
				table[i] = Cell();
			this->mod = mod;
		}

		void insertElement(string cont){
			hash<string> h_int;
			unsigned int num_hash = h_int(cont);
			int index = num_hash%mod;

			if(table[index].cont == EMPTY)
				table[index] = Cell(cont);
			else{
				colision++;
				Cell *key = new Cell(cont);
				insertBinaryTree(key, &table[index]);
			}
		}

		void fillHash(int num){
			mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
			uniform_int_distribution<int> unif_keysize(1, 5);
			uniform_int_distribution<int> unif_char(65, 90);
			string key;
			int keysize;

			for(int i=0; i<num; i++){
				keysize = unif_keysize(rng);
				key = "";
				for(int j=0; j<keysize; j++)
					key += static_cast<char>(unif_char(rng));
				this->insertElement(key);
			}
		}

		void leHash(){
			int j;
			for(int i=0; i<mod; i++){
				cout<<i;
				if(table[i].right != NULL || table[i].left != NULL){
					j = 0;
					leBinaryTree(&table[i], &j);
				}
				else{
					if(table[i].cont != EMPTY)
						cout<<" -> "<<table[i].cont<<" -> \\"<<endl;
					else
						cout<<" -> \\"<<endl;
				}
			}
		}

		int searchFor(string cont){
			hash<string> h_int;
			unsigned int num_hash = h_int(cont);
			int index = num_hash%mod;

			if(table[index].cont==EMPTY){
				cout<<"\""<<cont<<"\" não encontrado\n";
				return -1;
			}else{
				Cell *aux = &table[index];
				do{
					if(aux->cont == cont){
						cout<<"\""<<cont<<"\" encontrado"<<endl;
						return index;
					}
					
					if(cont < aux->cont)
						aux = aux->left;
					else
						aux = aux->right;
				}while(aux);
				cout<<"\""<<cont<<"\" não encontrado\n";
				return -1;
			}
		}

		void deleteElement(string cont){
			int index = searchFor(cont);
			if(index != -1){
				Cell *aux = &table[index];
				if(aux->cont == cont && aux->right == NULL && aux->left == NULL){
					aux->cont = EMPTY;
					cout<<"\""<<cont<<"\" apagado"<<endl;
				}
				else{
					deleteBinaryElement(aux, cont, index);
					cout<<"\""<<cont<<"\" apagado"<<endl;
				}
				
			}
		}

		void deleteBinaryElement(Cell *in, string cont, int index){
			string *vec = (string *) malloc(sizeof(string)*1000);
			int i = 0;
			writeTreeInVector(in, &i, cont, vec);
			free(table[index].right);
			free(table[index].left);
			table[index] = Cell(EMPTY);
			for(int j=0; j<i; j++)
				this->insertElement(vec[j]);
		}
};

int main(int argc, char **argv){
	for(int i=1; i<NUMBER_OF_TESTS+1; i++){
		int mod = atoi(argv[i]);
		for(int j=4; j<=2*NUMBER_OF_TESTS; j++){
			int numbers = atoi(argv[j]);
			cout<<"M = "<<mod<<" N = "<<numbers<<endl;

			Hash h = Hash(mod);
			double inicio = high_resolution_clock::now().time_since_epoch().count();
			h.fillHash(numbers);;
			cout<<"Tempo: "<< (high_resolution_clock::now().time_since_epoch().count() - inicio)/1000000<<" ms"<<endl;
			cout<<"Colisões = "<<h.colision<<endl<<endl;
		}
	}


}