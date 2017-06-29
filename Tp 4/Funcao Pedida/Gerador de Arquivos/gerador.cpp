#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <chrono>


using namespace std;

int main(){
	const int num_keys = 10000;
	ofstream fins, fsch, fdel;
	int keysize, i, j;
	string key;

	mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> unif_keysize(10, 30);
	uniform_int_distribution<int> unif_char(65, 90);
	uniform_real_distribution<double> unif_dbl(0, 1);

	fins.open("../chaves-inserir.txt");
	fsch.open("../chaves-pesquisar.txt");
	fdel.open("../chaves-apagar.txt");

	for(i=0; i<num_keys; i++){
		keysize = unif_keysize(rng);
		key = "";
		for(j=0; j<keysize; j++)
		key += static_cast<char>(unif_char(rng));
		fins << key << endl;
		if(unif_dbl(rng) < 0.3) fsch << key << endl;
		if(unif_dbl(rng) < 0.3) fdel << key << endl;
	}

	fins.close();
	fsch.close();
	fdel.close();
	return 0;
}