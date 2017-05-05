SOURCE = maxmin

all: compila linkedita executa

compila:
	g++ $(SOURCE).cpp -c -Wall -std=c++11 -g

linkedita:
	g++ $(SOURCE).o -o $(SOURCE).exe

executa:
	./$(SOURCE).exe

executa-passo:
	gdb $(SOURCE).exe

limpa:
	rm -f $(SOURCE).o $(SOURCE).exe
