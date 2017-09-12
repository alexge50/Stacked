//
// Created by alex on 9/12/17.
//

#ifndef STACKED_DEBUGSTACKEDLANGUAGEMANAGER_H
#define STACKED_DEBUGSTACKEDLANGUAGEMANAGER_H


#include <Stacked/IStackedLanguageManager.h>
#include <Stacked/StackedLanguageManager.h>

enum DebugLevel
{
    DEBUG_OFF = 0,
    DEBUG_ON = 1,
    DEBUG_VERBOSE = 2
};

class DebugStackedLanguageManager : IStackedLanguageManager
{
public:
    DebugStackedLanguageManager(FILE *debugFile, DebugLevel debugLevel);
    virtual ~DebugStackedLanguageManager() = default;

    /*stack operations*/
    virtual void newStack(std::string);
    virtual int nextElement(std::string);

    virtual void resetStack(std::string);
    virtual void popStack(std::string);
    virtual void pushStack(std::string, int value);

    virtual bool greaterThanOperation(std::string, std::string);
    virtual bool lessThanOperation(std::string, std::string);
    virtual bool equalOperation(std::string, std::string);
    virtual bool notEqualOperation(std::string, std::string);
    virtual bool notEmptyOperation(std::string);

    /*functions operations*/
    virtual void call(std::string); //unavailable
    virtual void signal(std::string);

    /* utility functions */
    virtual void addCall(std::string); //unavailable

    virtual bool isInMemory(std::string);
    virtual Stack* getStack(std::string);

    virtual void internalAddSignal(std::string name, Signal*);

private:
    StackedLanguageManager m_manager;
    FILE *m_debugFile;
    DebugLevel m_debugLevel;
};


#endif //STACKED_DEBUGSTACKEDLANGUAGEMANAGER_H
