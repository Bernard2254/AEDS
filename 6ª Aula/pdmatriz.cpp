#include <iostream>
#include <limits>

using namespace std;

int min_oper_multi_matriz(int n, int dims[]);

int main()
{
    int n = 4;
    int dims[] = {2, 30, 20, 5, 10}; // matrizes em ordens 2/30 30/20 20/5 5/10

    cout << min_oper_multi_matriz(n, dims) << endl;

    return 0;
}

int min_oper_multi_matriz(int n, int dims[])
{
    int i, j, k, aux, min_operacoes;
	int e;
    int **custo;

    //aloca tabela de custo e define o custo 0 de i para i
    custo = new int*[n];
    for(i = 0; i < n; i++)
        custo[i] = new int[n];
	
	//queremos no final o menor valor do multiplicatorio das n matrizes
	//custo[i][j] e o menor custo para multiplicar M_i*M_{i+1}*...*M_j
	//cada diagonal da matriz representa um estagio
	
	//custo[i][i+e] = numeric_limits<int>::max();	//nao se conhece, logo infinito
	
	cout << "dimensoes: " << endl;
	for(i = 0; i <= n; i++)
		cout << i << ':' << dims[i] << ", ";
	cout << endl;
	
	//configuracao do estagio inicial e = 0
	cout << "estagio: " << 0 << endl;
	for(i = 0; i < n; i++)
	{
        custo[i][i] = 0;
		cout << "c_{" << i << ", " << i << "} = " << custo[i][i] << ", ";
	}
	cout << endl;
	
	//proximos estagios
	for(e = 1; e < n; e++)
	{
		cout << "estagio: " << e << endl;
		//queremos encontrar o melhor custo[i][i+e]
		for(i = 0; i < n-e; i++)
		{
			j = i + e;
			cout << "c_{" << i << ", " << j << "} = ";
			
			//para isso devemos encontrar o melhor k \in {i, i+1, ..., j-1}
			//que minimize z = custo[i][k] + custo[k+1][j] + dims[i-1]*dims[k]*dims[j]
			min_operacoes = numeric_limits<int>::max();	//menor numero de operacoes local: nao se conhece, logo infinito
			for(k = i; k < j; k++)
			{
				aux = custo[i][k] + custo[k+1][j] + dims[i]*dims[k+1]*dims[j+1];
				if(aux < min_operacoes)
					min_operacoes = aux;
			}
			custo[i][j] = min_operacoes;
			cout << custo[i][j] << ", ";
		}
		cout << endl;
	}

    min_operacoes = custo[0][n-1];

    //desaloca tabela
    for(i = 0; i < n; i++) delete[] custo[i];
    delete[] custo;

    return min_operacoes;
}
