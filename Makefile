COMPILER=g++

DEPS  = StackedLanguageManager.h StackedLanguageManager.h Signal.h Signals.h Stream/FileStream.h Stream/IStream.h
OBJ = stacked.o StackedInterpreter.o StackedLanguageManager.o Signal.o Stream/FileStream.o Stream/IStream.o

all: Stacked

%.o: %.c $(DEPS) 
	$(CC) -c -o $@ $<

Stacked: $(OBJ)
	gcc -std=c++11 -lstdc++ -o Stacked $(OBJ)

clean:
	rm -f *.o Stream/*.o Stacked
