SOURCE = natal

all: compile link run destroy

compile:
	g++ $(SOURCE).cpp -c -Wall -std=c++11

link:
	g++ $(SOURCE).o -o $(SOURCE)

run:
	./$(SOURCE) < in

destroy:
	rm -rf ./$(SOURCE) $(SOURCE).o