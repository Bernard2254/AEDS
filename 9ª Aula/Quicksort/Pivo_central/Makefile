SOURCE = pivo_central

all: compile link run destroy

compile:
	g++ $(SOURCE).cpp -c -Wall -std=c++11 

link:
	g++ $(SOURCE).o -o $(SOURCE)

run:
	./$(SOURCE)

executa-passo:
	gdb $(SOURCE).exe

destroy:
	rm -f $(SOURCE).o $(SOURCE)
