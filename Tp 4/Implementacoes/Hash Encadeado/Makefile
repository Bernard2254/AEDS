SOURCE = hash

all: compile link run destroy

compile: 
	g++ $(SOURCE).cpp -c -std=c++11 -Wall

link:
	g++ $(SOURCE).o -o $(SOURCE)
run:
	./$(SOURCE) 500 1000 5000 2000 7000 10000
destroy:
	rm -rf ./$(SOURCE) *.o