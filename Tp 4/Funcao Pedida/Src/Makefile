FORMAT= .cpp
CC= g++
SRC=$(wildcard *$(FORMAT))
EXEC= main
CFLAGS= -Wall -std=c++11

all: compile link run

compile:
	$(CC) $(SRC) -c $(CFLAGS)

link:
	$(CC) $(SRC) -o $(EXEC) $(CFLAGS)

run:
	./$(EXEC) 500 1000 5000 2000 7000 10000

destroy:
	rm -rf *.o ./$(EXEC)

unique: unique_compile link run


unique_compile:
	$(CC) $(FILE).cpp -c $(CFLAGS)
