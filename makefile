## Artificial Neural Network ##

# - VARIABLES

CC = g++
MAINCODE = main
CODE1 = neuron
CODE2 = artificialNeuralNetwork
EXE = ./a.out

# - SCRIPT

OS := $(shell uname)
ifeq ($(OS),Darwin)
    all:
	$(CC) -c $(CODE1).cpp
	$(CC) -c $(MAINCODE).cpp
	$(CC) $(CODE1).cpp $(MAINCODE).cpp
	$(EXE)
	rm $(MAINCODE).o
	rm $(CODE1).o
else
    all:
	$(CC) -c $(CODE1).cpp
	$(CC) -c $(CODE2).cpp
	$(CC) -c $(MAINCODE).cpp
	$(CC) $(CODE1).o $(CODE2).o $(MAINCODE).o
	$(EXE)
	rm $(MAINCODE).o
	rm $(CODE1).o
	rm $(CODE2).o
	rm $(EXE)
endif



