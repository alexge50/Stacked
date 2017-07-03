COMPILER=g++

DEPS  = StackedLanguageManager.h StackedLanguageManager.h
OBJ = stacked.o StackedInterpreter.o StackedLanguageManager.o

all: Stacked

%.o: %.c $(DEPS) 
	$(CC) -c -o $@ $<

Stacked: $(OBJ)
	gcc -lstdc++ -o Stacked $(OBJ)

clean:
	rm -f *.o Stacked
