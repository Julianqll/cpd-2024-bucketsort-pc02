FLAGS=-O2 -fpermissive

CC=g++

RM=rm -f

EXEC=bucketsort

all: $(EXEC)

$(EXEC): main.c bucketsort.c bucketsort.h
	$(CC) $(FLAGS) $(EXEC).c -c -o $(EXEC).o
	$(CC) $(FLAGS) main.c -c -o main.o
	$(CC) $(FLAGS) main.o $(EXEC).o -o $(EXEC)

run:
	./$(EXEC)

clean:
	$(RM) main.o $(EXEC).o $(EXEC)
