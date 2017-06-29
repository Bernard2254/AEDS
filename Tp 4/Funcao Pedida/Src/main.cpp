#include "function.hpp"

int main(int argc, char ** argv){
	for(int i=1; i<(argc-1)/2+1; i++){
		int mod = atoi(argv[i]);
		for(int j=4; j<=2*(argc-1)/2; j++){
			int numbers = atoi(argv[j]);
			magicFunction(mod, numbers);
		}
	}
}