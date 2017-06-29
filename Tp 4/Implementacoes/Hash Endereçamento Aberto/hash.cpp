#include <iostream>
#include <string>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

#define EMPTY " "

class Hash{
	public:
		string *table;
		int mod, colision = 0;

		Hash(int mod){
			this->table = new string[mod];
			for(int i=0; i<mod; i++)
				table[i] = EMPTY;
			this->mod = mod;
		}

		int insertElement(string cont){
			hash<string> h_int;
			unsigned int num_hash = h_int(cont);
			int index = num_hash%mod;

			if(table[index]==EMPTY)
				table[index] = cont;
			else{
				int init = index;
				colision++;
				if(index!=mod-1)
					index++;
				else
					index=0;
				while(table[index]!=EMPTY){
					if(index!=mod-1){
						if(index+1 == init){
							cout<<"Tabela cheia, não foi possível inserir \""<<cont<<"\"\n";
							return 0;
						}
					}else{
						if(init == 0){
							cout<<"Tabela cheia, não foi possível inserir \""<<cont<<"\"\n";
							return 0;
						}	
					}
					if(index+1 == mod)
						index=-1;
					index++; colision++;
				}
				table[index] = cont;
			}
			return 1;
		}

		void fillHash(int num){
			mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
			uniform_int_distribution<int> unif_keysize(1, 20);
			uniform_int_distribution<int> unif_char(65, 90);
			string key;
			int keysize;

			for(int i=0; i<num; i++){
				keysize = unif_keysize(rng);
				key = "";
				for(int j=0; j<keysize; j++)
					key += static_cast<char>(unif_char(rng));
				if(!this->insertElement(key))
					return;
			}
		}

		void leHash(){
			for(int i=0; i<mod; i++){
				cout<<i;
				if(table[i] != EMPTY)
					cout<<" -> "<<table[i];
				cout<<" -> \\";
				cout<<endl;
			}
		}

		int searchFor(string cont){
			hash<string> h_int;
			unsigned int num_hash = h_int(cont);
			int index = num_hash%mod;

			if(table[index] ==  EMPTY){
				//cout<<"\""<<cont<<"\" não encontrado"<<endl;
				return -1;
			}else{
				if(table[index] == cont){
					//cout<<"\""<<cont<<"\" encontrado"<<endl;
					return index;
				}
				else{
					int init = index;
					if(index!=mod-1)
						index++;
					else
						index=0;
					while(table[index]!=cont){
						if(index!=mod-1){
							if(index+1 == init){
								//cout<<"\""<<cont<<"\""<<" não encontrado\n";
								return 0;
							}
						}else{
							if(init == 0){
								//cout<<"\""<<cont<<"\""<<" não encontrado\n";
								return 0;
							}	
						}
						if(index+1 == mod)
							index=-1;
						index++;
					}
					//cout<<"\""<<cont<<"\" encontrado"<<endl;
					return index;
				}
			}
		}

		int deleteElement(string cont){
			int index = searchFor(cont);
			if(index != -1){
				table[index] = ";";
				//cout<<"\""<<cont<<"\" apagado\n";
				return 1;
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