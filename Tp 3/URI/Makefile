SOURCE = questao

all: compile link run destroy

compile:
	g++ $(SOURCE).cpp -c -std=c++11
link:
	g++ $(SOURCE).o -o $(SOURCE)
run:
	./$(SOURCE) < in
destroy:
	rm -rf *.o ./$(SOURCE)