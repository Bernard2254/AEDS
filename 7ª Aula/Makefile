SOURCE = maxmin

all: fast run

fast:
	g++ $(SOURCE).cpp -Wall -std=c++11 -g -o $(SOURCE)

run_obj: make link run

make:
	g++ $(SOURCE).cpp -c -Wall -std=c++11 -g

link:
	g++ $(SOURCE).o -o $(SOURCE)

run:
	./$(SOURCE)

debug:
	gdb $(SOURCE)

clean:
	rm -f $(SOURCE).o $(SOURCE)
