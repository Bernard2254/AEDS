SOURCE = arrayHash

all: compile link run destroy

compile: 
	g++ $(SOURCE).cpp -c -std=c++11 -Wall

link:
	g++ $(SOURCE).o -o $(SOURCE)
run:
	./$(SOURCE) < entrada
destroy:
	rm -rf ./$(SOURCE) *.o