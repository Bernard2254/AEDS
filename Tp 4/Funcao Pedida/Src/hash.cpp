#include "hash.hpp"

void insertBinaryTree(Cell_Binaria *table, Cell_Binaria *inicio){
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

void leBinaryTree(Cell_Binaria *table, int *i){;
	if(!table)
		return;
	leBinaryTree(table->left, i);
	*i = *i+1;
	cout<<"\t"<<*i<<" -> ";
	cout<<table->cont<<endl;
	leBinaryTree(table->right, i);
}

void writeTreeInVector(Cell_Binaria *table, int *i, string cont, string *vec){;
	if(!table)
		return;
	writeTreeInVector(table->left, i, cont, vec);
	if(table->cont != cont){
		vec[*i] = table->cont;
		*i = *i+1;
	}
	writeTreeInVector(table->right, i, cont, vec);
}




Hash_Arvore_Binaria::Hash_Arvore_Binaria(int mod){
	this->table = new Cell_Binaria[mod];
	for(int i=0; i<mod; i++)
		table[i] = Cell_Binaria();
	this->mod = mod;
}

void Hash_Arvore_Binaria::insertElement(string cont){
	hash<string> h_int;
	unsigned int num_hash = h_int(cont);
	int index = num_hash%mod;

	if(table[index].cont == EMPTY)
		table[index] = Cell_Binaria(cont);
	else{
		colision++;
		Cell_Binaria *key = new Cell_Binaria(cont);
		insertBinaryTree(key, &table[index]);
	}
}

void Hash_Arvore_Binaria::fillHash(int num){
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

void Hash_Arvore_Binaria::leHash(){
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

int Hash_Arvore_Binaria::searchFor(string cont){
	hash<string> h_int;
	unsigned int num_hash = h_int(cont);
	int index = num_hash%mod;

	if(table[index].cont==EMPTY){
		//cout<<"\""<<cont<<"\" não encontrado\n";
		return -1;
	}else{
		Cell_Binaria *aux = &table[index];
		do{
			if(aux->cont == cont){
				//cout<<"\""<<cont<<"\" encontrado"<<endl;
				return index;
			}
			
			if(cont < aux->cont)
				aux = aux->left;
			else
				aux = aux->right;
		}while(aux);
		//cout<<"\""<<cont<<"\" não encontrado\n";
		return -1;
	}
}

int Hash_Arvore_Binaria::deleteElement(string cont){
	int index = searchFor(cont);
	if(index != -1){
		Cell_Binaria *aux = &table[index];
		if(aux->cont == cont && aux->right == NULL && aux->left == NULL){
			aux->cont = EMPTY;
			//cout<<"\""<<cont<<"\" apagado"<<endl;
			return 1;
		}
		else{
			deleteBinaryElement(aux, cont, index);
			//cout<<"\""<<cont<<"\" apagado"<<endl;
			return 1;
		}
		
	}
	return 0;
}

void Hash_Arvore_Binaria::deleteBinaryElement(Cell_Binaria *in, string cont, int index){
	string *vec = new string[mod];
	int i = 0;
	writeTreeInVector(in, &i, cont, vec);
	free(table[index].right);
	free(table[index].left);
	table[index] = Cell_Binaria(EMPTY);
	for(int j=0; j<i; j++)
		this->insertElement(vec[j]);
}

Hash_Encadeado::Hash_Encadeado(int mod){
	this->table = new Cell_Encadeada[mod];
	this->mod = mod;
}

void Hash_Encadeado::insertElement(string cont){
	hash<string> h_int;
	unsigned int num_hash = h_int(cont);
	int index = num_hash%mod;

	Cell_Encadeada *key = new Cell_Encadeada();
	key->cont = cont;
	key->next = NULL;

	if(table[index].next==NULL)
		table[index].next = key;
	else{
		colision++;
		Cell_Encadeada *aux = table[index].next;
		while(aux->next)
			aux = aux->next;
		aux->next = key;
	}
}

void Hash_Encadeado::fillHash(int num){
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

void Hash_Encadeado::leHash(){
	for(int i=0; i<mod; i++){
		cout<<i;
		Cell_Encadeada aux = table[i];
		if(aux.next != NULL)
			cout<<" -> "<<aux.cont;
		Cell_Encadeada *aux2 = aux.next;
		while(aux2){
			cout<<" -> "<<aux2->cont;
			aux2 = aux2->next;
		}
		cout<<" -> \\";
		cout<<endl;
	}
}

int Hash_Encadeado::searchFor(string cont){
	hash<string> h_int;
	unsigned int num_hash = h_int(cont);
	int index = num_hash%mod;

	if(table[index].next){
		Cell_Encadeada *aux = table[index].next;
		while(aux){
			if(aux->cont == cont){
				//cout<<"\""<<cont<<"\" encontrado"<<endl;
				return index;
			}
			aux = aux->next;
		}
	}
	//cout<<"\""<<cont<<"\" não encontrado"<<endl;
	return -1;
}

int Hash_Encadeado::deleteElement(string cont){
	int index = searchFor(cont);
	if(index != -1){
		Cell_Encadeada *aux2 = table[index].next;
		Cell_Encadeada *aux = table[index].next;
		while(aux){
			if(aux->cont == cont){
				aux2->next = aux->next;
				//free(aux);
				//cout<<"\""<<cont<<"\" apagado\n";
				return 1;
			}
			aux2 = aux;
			aux = aux->next;
		}	
	}
	return 0;
}

Hash_Enderecamento_Aberto::Hash_Enderecamento_Aberto(int mod){
	this->table = new string[mod];
	for(int i=0; i<mod; i++)
		table[i] = EMPTY;
	this->mod = mod;
}

int Hash_Enderecamento_Aberto::insertElement(string cont){
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
					//cout<<"Tabela cheia, não foi possível inserir \""<<cont<<"\"\n";
					return 0;
				}
			}else{
				if(init == 0){
					//cout<<"Tabela cheia, não foi possível inserir \""<<cont<<"\"\n";
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

void Hash_Enderecamento_Aberto::fillHash(int num){
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

void Hash_Enderecamento_Aberto::leHash(){
	for(int i=0; i<mod; i++){
		cout<<i;
		if(table[i] != EMPTY)
			cout<<" -> "<<table[i];
		cout<<" -> \\";
		cout<<endl;
	}
}

int Hash_Enderecamento_Aberto::searchFor(string cont){
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
			return index;
		}
	}
}

int Hash_Enderecamento_Aberto::deleteElement(string cont){
	int index = searchFor(cont);
	if(index != -1){
		table[index] = ";";
		//cout<<"\""<<cont<<"\" apagado\n";
		return 1;
	}
	return 0;
}