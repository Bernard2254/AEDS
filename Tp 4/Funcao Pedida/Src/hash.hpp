#ifndef HASH_HPP
#define HASH_HPP
#include "cell.hpp"

#define EMPTY " "

void insertBinaryTree(Cell_Binaria *table, Cell_Binaria *inicio);
void leBinaryTree(Cell_Binaria *table, int *i);
void writeTreeInVector(Cell_Binaria *table, int *i, string cont, string *vec);

class Hash_Arvore_Binaria{
	public:
		Cell_Binaria *table;
		int mod, colision = 0;

		Hash_Arvore_Binaria(int mod);
		void insertElement(string cont);
		void fillHash(int num);
		void leHash();
		int searchFor(string cont);
		int deleteElement(string cont);
		void deleteBinaryElement(Cell_Binaria *in, string cont, int index);
};

class Hash_Encadeado{
	public:
		Cell_Encadeada *table;
		int mod, colision = 0;

		Hash_Encadeado(int mod);
		void insertElement(string cont);
		void fillHash(int num);
		void leHash();
		int searchFor(string cont);
		int deleteElement(string cont);
};

class Hash_Enderecamento_Aberto{
	public:
		string *table;
		int mod, colision = 0;
		Hash_Enderecamento_Aberto();
		Hash_Enderecamento_Aberto(int mod);
		int insertElement(string cont);
		void fillHash(int num);
		void leHash();
		int searchFor(string cont);
		int deleteElement(string cont);
};
#endif