#include <iostream>

using namespace std;

int Fibonacci (int &a, int &b){
	return a+b;
}

void FibonacciPlay(int init ,int n, int &result, int anterior){
		if(n==1){
			anterior=Fibonacci(init, anterior);
		}
		FibonacciPlay(init, n, result);
}


int main(){
	int n;
	int result = 1;
	cin >> n;

	FibonacciPlay(1, n, result, 1);
}