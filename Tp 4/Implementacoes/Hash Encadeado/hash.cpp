#include <iostream>
#include <string>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;


class Cell{
	public:
		string cont;
		Cell *next;

		Cell(){
			this->next = NULL;
		}

		Cell(string cont){
			this->cont = cont;
			this->next = NULL;
		}
};

class Hash{
	public:
		Cell *table;
		int mod, colision = 0;

		Hash(int mod){
			this->table = new Cell[mod];
			this->mod = mod;
		}

		void insertElement(string cont){
			hash<string> h_int;
			unsigned int num_hash = h_int(cont);
			int index = num_hash%mod;

			Cell *key = new Cell();
			key->cont = cont;
			key->next = NULL;

			if(table[index].next==NULL)
				table[index].next = key;
			else{
				colision++;
				Cell *aux = table[index].next;
				while(aux->next)
					aux = aux->next;
				aux->next = key;
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
			for(int i=0; i<mod; i++){
				cout<<i;
				Cell aux = table[i];
				if(aux.next != NULL)
					cout<<" -> "<<aux.cont;
				Cell *aux2 = aux.next;
				while(aux2){
					cout<<" -> "<<aux2->cont;
					aux2 = aux2->next;
				}
				cout<<" -> \\";
				cout<<endl;
			}
		}

		int searchFor(string cont){
			hash<string> h_int;
			unsigned int num_hash = h_int(cont);
			int index = num_hash%mod;

			if(table[index].next){
				Cell *aux = table[index].next;
				while(aux){
					if(aux->cont == cont){
						cout<<"\""<<cont<<"\" encontrado"<<endl;
						return index;
					}
					aux = aux->next;
				}
			}
			cout<<"\""<<cont<<"\" não encontrado"<<endl;
			return -1;
		}

		int deleteElement(string cont){
			int index = searchFor(cont);
			if(index != -1){
				Cell *aux2 = table[index].next;
				Cell *aux = table[index].next;
				while(aux){
					if(aux->cont == cont){
						aux2->next = aux->next;
						free(aux);
						//cout<<"\""<<cont<<"\" apagado\n";
						return 1;
					}
					aux2 = aux;
					aux = aux->next;
				}	
			}
			return 0;

		}
};

int main(int argc, char **argv){
	for(int i=1; i<(argc-1)/2+1; i++){
		int mod = atoi(argv[i]);
		for(int j=4; j<=2*(argc-1)/2; j++){
			int numbers = atoi(argv[j]);
			cout<<"M = "<<mod<<" N = "<<numbers<<endl;

			Hash h = Hash(mod);
			double inicio = high_resolution_clock::now().time_since_epoch().count();
			h.fillHash(numbers);
			cout<<"Tempo: "<< (high_resolution_clock::now().time_since_epoch().count() - inicio)/1000000<<" ms"<<endl;
			cout<<"Colisões = "<<h.colision<<endl<<endl;
		}
	}

}