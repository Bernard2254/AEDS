#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include "hash.hpp"
#include <fstream>

void insertInFile(int M, int N, Hash_Arvore_Binaria *h1, Hash_Encadeado *h2, Hash_Enderecamento_Aberto *h3, double *vec1, double *vec2);
void searchElements(int M, int N, Hash_Arvore_Binaria *h1, Hash_Encadeado *h2, Hash_Enderecamento_Aberto *h3, double *vetor);
void deleteElements(int M, int N, Hash_Arvore_Binaria *h1, Hash_Encadeado *h2, Hash_Enderecamento_Aberto *h3, double *vetor);
void magicFunction(int M, int N);

#endif