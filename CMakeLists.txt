cmake_minimum_required(VERSION 3.6)
project(Stacked)

set(CMAKE_CXX_STANDARD 11)

set(LIBRARY_SOURCE_FILES
        src/AbstractSyntaxTree/Comparation/Equal.cpp
        include/Stacked/AbstractSyntaxTree/Comparation/Equal.h
        src/AbstractSyntaxTree/Comparation/GreaterThan.cpp
        include/Stacked/AbstractSyntaxTree/Comparation/GreaterThan.h
        src/AbstractSyntaxTree/Comparation/LessThan.cpp
        include/Stacked/AbstractSyntaxTree/Comparation/LessThan.h
        src/AbstractSyntaxTree/Comparation/NotEmpty.cpp
        include/Stacked/AbstractSyntaxTree/Comparation/NotEmpty.h
        src/AbstractSyntaxTree/Comparation/NotEqual.cpp
        include/Stacked/AbstractSyntaxTree/Comparation/NotEqual.h
        src/AbstractSyntaxTree/Expression/Addition.cpp
        include/Stacked/AbstractSyntaxTree/Expression/Addition.h
        src/AbstractSyntaxTree/Expression/Division.cpp
        include/Stacked/AbstractSyntaxTree/Expression/Division.h
        src/AbstractSyntaxTree/Expression/Mod.cpp
        include/Stacked/AbstractSyntaxTree/Expression/Mod.h
        src/AbstractSyntaxTree/Expression/Multiplication.cpp
        include/Stacked/AbstractSyntaxTree/Expression/Multiplication.h
        src/AbstractSyntaxTree/Expression/Subtraction.cpp
        include/Stacked/AbstractSyntaxTree/Expression/Subtraction.h
        src/AbstractSyntaxTree/Comparation.cpp
        include/Stacked/AbstractSyntaxTree/Comparation.h
        src/AbstractSyntaxTree/ConstNumber.cpp
        include/Stacked/AbstractSyntaxTree/ConstNumber.h
        src/AbstractSyntaxTree/Expression.cpp
        include/Stacked/AbstractSyntaxTree/Expression.h
        src/AbstractSyntaxTree/If.cpp
        include/Stacked/AbstractSyntaxTree/If.h
        src/AbstractSyntaxTree/Instruction.cpp
        include/Stacked/AbstractSyntaxTree/Instruction.h
        src/AbstractSyntaxTree/InstructionBlock.cpp
        include/Stacked/AbstractSyntaxTree/InstructionBlock.h
        src/AbstractSyntaxTree/InvalidInstruction.cpp
        include/Stacked/AbstractSyntaxTree/InvalidInstruction.h
        src/AbstractSyntaxTree/NewStack.cpp
        include/Stacked/AbstractSyntaxTree/NewStack.h
        src/AbstractSyntaxTree/NextElement.cpp
        include/Stacked/AbstractSyntaxTree/NextElement.h
        src/AbstractSyntaxTree/PopStack.cpp
        include/Stacked/AbstractSyntaxTree/PopStack.h
        src/AbstractSyntaxTree/Program.cpp
        include/Stacked/AbstractSyntaxTree/Program.h
        src/AbstractSyntaxTree/PushStack.cpp
        include/Stacked/AbstractSyntaxTree/PushStack.h
        src/AbstractSyntaxTree/ResetStack.cpp
        include/Stacked/AbstractSyntaxTree/ResetStack.h
        src/AbstractSyntaxTree/SignalInstruction.cpp
        include/Stacked/AbstractSyntaxTree/SignalInstruction.h
        src/AbstractSyntaxTree/While.cpp
        include/Stacked/AbstractSyntaxTree/While.h
        src/Stream/FileStream.cpp
        include/Stacked/Stream/FileStream.h
        src/Stream/IStream.cpp
        include/Stacked/Stream/IStream.h
        include/Stacked/AbstractSyntaxTree.h
        include/Stacked/LanguageVersion.h
        src/Error.cpp
        include/Stacked/Error.h
        src/Signal.cpp
        include/Stacked/Signal.h
        src/StackedInterpreter.cpp
        include/Stacked/StackedInterpreter.h
        include/Stacked/IStackedLanguageManager.h
        src/StackedLanguageManager.cpp
        include/Stacked/StackedLanguageManager.h
        src/Stack.cpp include/Stacked/Stack.h
        )

set(SOURCE_FILES
        Stacked/CommandLineArguments.cpp
        Stacked/CommandLineArguments.h
        Stacked/Version.h
        Stacked/stacked.cpp
        Stacked/Signals.h
       )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

add_executable(Stacked ${SOURCE_FILES} ${LIBRARY_SOURCE_FILES})
add_library(stacked STATIC ${LIBRARY_SOURCE_FILES})
add_library(stacked_shared SHARED ${LIBRARY_SOURCE_FILES})

install(DIRECTORY include/Stacked DESTINATION include)
install(TARGETS Stacked DESTINATION bin)
install(TARGETS stacked DESTINATION lib)
install(TARGETS stacked_shared DESTINATION lib)