#include "../ordena.hpp"

int main(int argc, char** argv){
	int size;
	if(argc<=1)
		size=100;
	else
		size=atoi(argv[1]);
	int vec[size];
	mt19937 semente;
	uniform_int_distribution<tipo> unif_int_d(0, RAND);
	semente.seed(high_resolution_clock::now().time_since_epoch().count());
	for(int i=0; i<size;i++)
		vec[i] = unif_int_d(semente);
	Ordena teste(size);
	teste.Experimento(vec, size);
	return 0;
}
