COMPILER=g++

DEPS  = StackedInterpreter.h StackedLanguageManager.h Error.h Signal.h AbstractSyntaxTree.h Signals.h AbstractSyntaxTree/PopStack.h AbstractSyntaxTree/PushStack.h AbstractSyntaxTree/SignalInstruction.h AbstractSyntaxTree/ConstNumber.h AbstractSyntaxTree/InstructionBlock.h AbstractSyntaxTree/If.h AbstractSyntaxTree/ResetStack.h AbstractSyntaxTree/NextElement.h AbstractSyntaxTree/While.h AbstractSyntaxTree/Expression.h AbstractSyntaxTree/NewStack.h AbstractSyntaxTree/Program.h AbstractSyntaxTree/Instruction.h AbstractSyntaxTree/Comparation.h Stream/IStream.h Stream/FileStream.h AbstractSyntaxTree/Comparation/LessThan.h AbstractSyntaxTree/Comparation/NotEmpty.h AbstractSyntaxTree/Comparation/NotEqual.h AbstractSyntaxTree/Comparation/Equal.h AbstractSyntaxTree/Comparation/GreaterThan.h AbstractSyntaxTree/Expression/Addition.h AbstractSyntaxTree/Expression/Subtraction.h AbstractSyntaxTree/Expression/Mod.h AbstractSyntaxTree/Expression/Division.h AbstractSyntaxTree/Expression/Multiplication.h 
 

OBJ = Signal.o stacked.o Error.o StackedLanguageManager.o StackedInterpreter.o AbstractSyntaxTree/Expression.o AbstractSyntaxTree/Instruction.o AbstractSyntaxTree/Program.o AbstractSyntaxTree/SignalInstruction.o AbstractSyntaxTree/If.o AbstractSyntaxTree/While.o AbstractSyntaxTree/ConstNumber.o AbstractSyntaxTree/PushStack.o AbstractSyntaxTree/NextElement.o AbstractSyntaxTree/ResetStack.o AbstractSyntaxTree/PopStack.o AbstractSyntaxTree/InstructionBlock.o AbstractSyntaxTree/NewStack.o AbstractSyntaxTree/Comparation.o Stream/IStream.o Stream/FileStream.o AbstractSyntaxTree/Comparation/NotEmpty.o AbstractSyntaxTree/Comparation/NotEqual.o AbstractSyntaxTree/Comparation/LessThan.o AbstractSyntaxTree/Comparation/GreaterThan.o AbstractSyntaxTree/Comparation/Equal.o AbstractSyntaxTree/Expression/Multiplication.o AbstractSyntaxTree/Expression/Addition.o AbstractSyntaxTree/Expression/Subtraction.o AbstractSyntaxTree/Expression/Mod.o AbstractSyntaxTree/Expression/Division.o 


all: Stacked

%.o: %.cpp $(DEPS) 
	$(CC) -std=c++0x -c -o $@ $<

**/%.o: %.cpp $(DEPS) 
	$(CC) -std=c++0x -c -o $@ $<

**/**/%.o: %.cpp $(DEPS) 
	$(CC) -std=c++0x -c -o $@ $<


Stacked: $(OBJ)
	gcc -std=c++0x -lstdc++ -o Stacked $(OBJ)

clean:
	#rm -f *.o Stream/*.o **/*.o **/*.o "AbstractSyntaxTree/*.o" "AbstractSyntaxTree/Comparation/*.o" "AbstractSyntaxTree/Expression/*.o" Stacked
	rm -f *.o **/*.o **/**/*.o Stacked
