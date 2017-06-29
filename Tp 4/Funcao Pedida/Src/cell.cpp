#include "cell.hpp"


Cell_Binaria::Cell_Binaria(){
	cont = EMPTY;
}

Cell_Binaria::Cell_Binaria(string cont){
	this->cont = cont;
}

Cell_Encadeada::Cell_Encadeada(){
		next = NULL;
	}

Cell_Encadeada::Cell_Encadeada(string cont){
	this->cont = cont;
	next = NULL;
}