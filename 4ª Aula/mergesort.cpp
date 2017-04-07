#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

void IniciaVetor(int v[], int n);
void ImprimeVetor(int v[], int n);

void Merge(int v[], int e, int m, int d);
void MergeSortRecursivo(int v[], int e, int d);
void MergeSort(int v[], int n);

int main()
{
	int *v = nullptr;
	int n;
	
	//le dimensao
	cin >> n;
	
	//aloca v
	v = new int[n];
	
	IniciaVetor(v, n);
	ImprimeVetor(v, n);
	MergeSort(v, n);
	cout << endl;
	ImprimeVetor(v, n);
	
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

void Merge(int v[], int e, int m, int d)
{
	int i, j, k, *v_aux;
	
	//aloca vetor que recebera a juncao ordenada
	v_aux = new int[d - e + 1];
	
	i = e; j = m + 1; k = 0;
	
	//junta os dados de forma ordenada em v_aux
	while(i <= m && j <= d)
		if(v[i] < v[j])
			v_aux[k++] = v[i++]; //Pega o valor de v_aux[k] e depois soma, Pega o valor de v[i] e depois soma
		else
			v_aux[k++] = v[j++];
	//dados restantes
	while(i <= m)
		v_aux[k++] = v[i++];
	while(j <= d)
		v_aux[k++] = v[j++];
	
	//copia dos dados ordenados para o vetor original
	for(i = e; i <= d; i++)
		v[i] = v_aux[i - e];
	
	delete[] v_aux;
}

void MergeSortRecursivo(int v[], int e, int d)
{
	if(e < d) 
	{
		int m = (e + d) / 2;
		MergeSortRecursivo(v, e, m);
		MergeSortRecursivo(v, m + 1, d);
		Merge(v, e, m, d);
	}
}

void MergeSort(int v[], int n)
{
	MergeSortRecursivo(v, 0, n-1);
}
