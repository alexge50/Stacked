COMPILER=g++

DEPS  = StackedLanguageManager.h StackedLanguageManager.h Signal.h Signals.h
OBJ = stacked.o StackedInterpreter.o StackedLanguageManager.o Signal.o

all: Stacked

%.o: %.c $(DEPS) 
	$(CC) -c -o $@ $<

Stacked: $(OBJ)
	gcc -std=c++11 -lstdc++ -o Stacked $(OBJ)

clean:
	rm -f *.o Stacked
