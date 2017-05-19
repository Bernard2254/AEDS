SOURCE = insercao-lista

all: compile link run destroy

compile:
	g++ $(SOURCE).cpp -c -std=c++11
link:
	g++ $(SOURCE).o -o $(SOURCE)
run:
	./$(SOURCE)
destroy:
	rm -rf ./$(SOURCE) $(SOURCE).o 