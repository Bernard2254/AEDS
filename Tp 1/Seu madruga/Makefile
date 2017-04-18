SOURCE = seumadruga

all: compile link run destroy

compile:
	g++ $(SOURCE).cpp -c -Wall -w -std=c++11

link:
	g++ $(SOURCE).o -o $(SOURCE)

run:
	./$(SOURCE) < in

destroy:
	rm -r $(SOURCE).o $(SOURCE)
