#include <iostream>
#include "passeiocavalo.hpp"

using namespace std;

int main()
{
	c_map m;
	bool s;
	m.allocate(8, 8);
	s = m.horse_ride(0, 0);
	m.deallocate();
	
	if(s)
		cout << "solucao encontrada"<< endl;
	else
		cout << "sem solucao"<< endl;
	
	return 0;
}
