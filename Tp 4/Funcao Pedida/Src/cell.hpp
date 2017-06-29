#ifndef CELL_HPP
#define CELL_HPP
#include <iostream>
#include <string>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

#define NUMBER_OF_TESTS 3
#define EMPTY " "

class Cell_Binaria{
	public:
		string cont;
		Cell_Binaria *right = NULL;
		Cell_Binaria *left = NULL;

		Cell_Binaria();
		Cell_Binaria(string cont);
};

class Cell_Encadeada{
	public:
		string cont;
		Cell_Encadeada *next;

		Cell_Encadeada();
		Cell_Encadeada(string cont);
};

#endif