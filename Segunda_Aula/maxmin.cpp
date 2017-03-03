#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

void IniciaVetor(int v[], int n);
void ImprimeVetor(int v[], int n);

void MaxMin1(int v[], int n, int &min, int &max);
void MaxMin2(int v[], int n, int &min, int &max);
void MaxMin3(int v[], int n, int &min, int &max);

int main()
{
	int *v = nullptr;
	int n;
	int min, max;
	
	//le dimensao
	cin >> n;
	//se impar, incremeta por causa do MaxMin3
	cout << (n&1) << endl;
	if(n & 1) n++;
	
	//aloca v
	v = new int[n];
	
	IniciaVetor(v, n);
	ImprimeVetor(v, n);
	
	min = max = 0;
	MaxMin1(v, n, min, max);
	cout << min << ' ' << max << endl;
	
	min = max = 0;
	MaxMin2(v, n, min, max);
	cout << min << ' ' << max << endl;
	
	min = max = 0;
	MaxMin3(v, n, min, max);
	cout << min << ' ' << max << endl;
	
	//libera espaco alocado
	delete v;
	
	return 0;
}

void IniciaVetor(int v[], int n)
{
	//gerador de numeros aleatorios e objeto para geracao de numeros inteiros uniformes entre 0 e 1000
	mt19937 rng;
	uniform_int_distribution<int> unif_int_d(0, 1000);
	int i;
	
	//tempo atual como semente para o gerador de numeros aleatorios
	rng.seed(high_resolution_clock::now().time_since_epoch().count());
	
	for(i = 0; i < n; i++)
		v[i] = unif_int_d(rng);
}

void ImprimeVetor(int v[], int n)
{
	int i;
	
	for(i = 0; i < n; i++)
		cout << v[i] << ' ';
	cout << endl;
}

/* Numero de comparacoes:
 * Melhor caso, pior caso e caso medio: 2(n-1)
 */
void MaxMin1(int v[], int n, int &min, int &max)
{
	int i;
	
	min = max = v[0];
	for(i = 1; i < n; i++)
	{
		if(v[i] > max) max = v[i];
		if(v[i] < min) min = v[i];
	}
}

/* Numero de comparacoes:
 * Melhor caso: n-1,        v ordenado crescentemente
 * Pior caso:   2(n-1),     v ordenado decrescentemente
 * Caso medio:  3(n/2)-3/2, v[i] < max em metade das vezes
 */
void MaxMin2(int v[], int n, int &min, int &max)
{
	int i;
	
	min = max = v[0];
	for(i = 1; i < n; i++)
		if(v[i] > max)
			max = v[i];
		else if(v[i] < min)
			min = v[i];
}

/* Numero de comparacoes:
 * Melhor caso, pior caso e caso medio: 3(n/2)-2
 */
void MaxMin3(int v[], int n, int &min, int &max)
{
	int i;
	
	if(v[0] > v[1])
	{
		max = v[0];
		min = v[1];
	}
	else
	{
		max = v[1];
		min = v[0];
	}
	
	for(i = 2; i < n; i += 2)
	{
		if(v[i] > v[i+1])
		{
			if(v[i] > max)   max = v[i];
			if(v[i+1] < min) min = v[i+1];
		}
		else
		{
			if(v[i] < min)   min = v[i];
			if(v[i+1] > max) max = v[i+1];
		}
	}
}