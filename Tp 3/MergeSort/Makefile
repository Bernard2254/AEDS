SOURCE = mergesort

all: compile link run destroy

bash: compile link

compile:
	g++ $(SOURCE).cpp -c -std=c++11 -Wall
link:
	g++ $(SOURCE).o -o $(SOURCE)
run:
	./$(SOURCE)
destroy:
	rm -rf *.o ./$(SOURCE) 