#include "../ordena.hpp"

int main(int argc, char** argv){
	int size;
	if(argc<=1)
		size=100;
	else
		size=atoi(argv[1]);
	Ordena teste(size);
	teste.tempo.inicia();
	teste.insertion();
	teste.tempo.finaliza("Insertion", teste.TAM);
	teste.confere();
	return 0;
}