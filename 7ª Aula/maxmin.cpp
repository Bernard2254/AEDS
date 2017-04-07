#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

void IniciaVetor(int v[], int n);
void ImprimeVetor(int v[], int n);

void MaxMin4(int v[], int n, int &min, int &max);
void MaxMinR(int v[], int left, int right, int &min, int &max);

int main()
{
	int *v = nullptr;
	int n;
	int min, max;
	
	//le dimensao
	cin >> n;
	
	//aloca v
	v = new int[n];
	
	IniciaVetor(v, n);
	ImprimeVetor(v, n);
	
	min = max = 0;
	MaxMin4(v, n, min, max);
	cout << min << ' ' << max << endl;
	
	//libera espaco alocado
	delete[] v;
	
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
 * Melhor caso, pior caso e caso medio: 3(n/2)-2
 */
void MaxMin4(int v[], int n, int &min, int &max)
{
	MaxMinR(v, 0, n-1, min, max);
}

void MaxMinR(int v[], int left, int right, int &min, int &max)
{
	int middle;
	int min1, max1, min2, max2;
	
	if(right - left <= 1)
	{
		if(v[right] > v[left])
		{ max = v[right]; min = v[left]; }
		else
		{ min = v[right]; max = v[left]; }
	}
	else
	{
		middle = (right + left)/2;
		MaxMinR(v, left, middle, min1, max1);
		MaxMinR(v, middle+1, right, min2, max2);
		
		if(min1 < min2) min = min1;
		else min = min2;
		
		if(max1 > max2) max = max1;
		else max = max2;
	}
}
