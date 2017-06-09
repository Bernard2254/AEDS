#include "../ordena.hpp"

int main(int argc, char** argv){
	int size;
	if(argc<=1)
		size=100;
	else
		size=atoi(argv[1]);
	Ordena teste(size);
	teste.tempo.inicia();
	teste.shellSort();
	teste.confere();
	teste.tempo.finaliza("ShellSort", teste.TAM);

	return 0;
}