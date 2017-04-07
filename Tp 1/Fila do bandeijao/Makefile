SOURCE = fila_bandeijao

all: compile link run destroy

compile:
	g++ $(SOURCE).cpp -c -Wall -std=c++11

link:
	g++ $(SOURCE).o -o $(SOURCE)

run:
	./$(SOURCE) < in

destroy:
	rm -r $(SOURCE).o $(SOURCE)