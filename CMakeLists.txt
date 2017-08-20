cmake_minimum_required(VERSION 3.8)
project(Stacked)

set(CMAKE_CXX_STANDARD 11)

set(LIBRARY_SOURCE_FILES
        src/AbstractSyntaxTree/Comparation/Equal.cpp
        include/AbstractSyntaxTree/Comparation/Equal.h
        src/AbstractSyntaxTree/Comparation/GreaterThan.cpp
        include/AbstractSyntaxTree/Comparation/GreaterThan.h
        src/AbstractSyntaxTree/Comparation/LessThan.cpp
        include/AbstractSyntaxTree/Comparation/LessThan.h
        src/AbstractSyntaxTree/Comparation/NotEmpty.cpp
        include/AbstractSyntaxTree/Comparation/NotEmpty.h
        src/AbstractSyntaxTree/Comparation/NotEqual.cpp
        include/AbstractSyntaxTree/Comparation/NotEqual.h
        src/AbstractSyntaxTree/Expression/Addition.cpp
        include/AbstractSyntaxTree/Expression/Addition.h
        src/AbstractSyntaxTree/Expression/Division.cpp
        include/AbstractSyntaxTree/Expression/Division.h
        src/AbstractSyntaxTree/Expression/Mod.cpp
        include/AbstractSyntaxTree/Expression/Mod.h
        src/AbstractSyntaxTree/Expression/Multiplication.cpp
        include/AbstractSyntaxTree/Expression/Multiplication.h
        src/AbstractSyntaxTree/Expression/Subtraction.cpp
        include/AbstractSyntaxTree/Expression/Subtraction.h
        src/AbstractSyntaxTree/Comparation.cpp
        include/AbstractSyntaxTree/Comparation.h
        src/AbstractSyntaxTree/ConstNumber.cpp
        include/AbstractSyntaxTree/ConstNumber.h
        src/AbstractSyntaxTree/Expression.cpp
        include/AbstractSyntaxTree/Expression.h
        src/AbstractSyntaxTree/If.cpp
        include/AbstractSyntaxTree/If.h
        src/AbstractSyntaxTree/Instruction.cpp
        include/AbstractSyntaxTree/Instruction.h
        src/AbstractSyntaxTree/InstructionBlock.cpp
        include/AbstractSyntaxTree/InstructionBlock.h
        src/AbstractSyntaxTree/InvalidInstruction.cpp
        include/AbstractSyntaxTree/InvalidInstruction.h
        src/AbstractSyntaxTree/NewStack.cpp
        include/AbstractSyntaxTree/NewStack.h
        src/AbstractSyntaxTree/NextElement.cpp
        include/AbstractSyntaxTree/NextElement.h
        src/AbstractSyntaxTree/PopStack.cpp
        include/AbstractSyntaxTree/PopStack.h
        src/AbstractSyntaxTree/Program.cpp
        include/AbstractSyntaxTree/Program.h
        src/AbstractSyntaxTree/PushStack.cpp
        include/AbstractSyntaxTree/PushStack.h
        src/AbstractSyntaxTree/ResetStack.cpp
        include/AbstractSyntaxTree/ResetStack.h
        src/AbstractSyntaxTree/SignalInstruction.cpp
        include/AbstractSyntaxTree/SignalInstruction.h
        src/AbstractSyntaxTree/While.cpp
        include/AbstractSyntaxTree/While.h
        src/Stream/FileStream.cpp
        include/Stream/FileStream.h
        src/Stream/IStream.cpp
        include/Stream/IStream.h
        include/AbstractSyntaxTree.h
)

set(SOURCE_FILES

        Stacked/CommandLineArguments.cpp
        Stacked/CommandLineArguments.h
        src/Error.cpp
        include/Error.h
        src/Signal.cpp
        include/Signal.h
        Stacked/Signals.h
        Stacked/stacked.cpp
        src/StackedInterpreter.cpp
        include/StackedInterpreter.h
        src/StackedLanguageManager.cpp
        include/StackedLanguageManager.h)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

add_executable(Stacked ${SOURCE_FILES} ${LIBRARY_SOURCE_FILES})
add_library(stacked STATIC ${LIBRARY_SOURCE_FILES})
add_library(stacked_shared SHARED ${LIBRARY_SOURCE_FILES})