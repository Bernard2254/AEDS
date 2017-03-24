#ifndef PASSEIOCAVALO_H
#define PASSEIOCAVALO_H

#include <iostream>
#include <iomanip>

using namespace std;

class c_map
{
public:
	int ** map;
	int nrows, ncols;
	int possible_moves[8][2];
	
	c_map();
	~c_map();
	
	bool is_allocated();
	void allocate(int num_rows, int num_cols);
	
	//desaloca
	void deallocate();
	
	//move o cavalo
	bool play(int col, int row, int value); //value índice do passo seguinte
	
	//desfaz jogada
	void undo_play(int col, int row);
	
	//passeio do cavalo
	bool horse_ride(int col, int row);
	
	//tenta movimento, verifica se é possível
	void try_move(int move_id, int col, int row, bool &success);
	
	//imprime matriz
	void print_map();
};

//***********************//

void try_move(c_map &map, int move_id, int col, int row, bool &success);

#endif
