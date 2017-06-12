#include "../../ordena.hpp"

int main(int argc, char** argv){
	int size;
	if(argc<=1)
		size=100;
	else
		size=atoi(argv[1]);
	Ordena teste(size);
	teste.tempo.inicia();
	teste.quickSortInsertion(0, size-1);
	teste.tempo.finaliza("QuickSort parcial", teste.TAM);
	teste.confere();

	return 0;
}