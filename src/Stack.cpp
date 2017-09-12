//
// Created by alex on 9/12/17.
//

#include "Stacked/Stack.h"

/***********/

Stack::Stack()
{
    i = 0;
};

int Stack::nextElement()
{
    if(i < stack.size())
        return stack[i--];
    else
        return -1;
}

int Stack::top()
{
    if(stack.size() != 0)
        return stack[stack.size() - 1];
    else
        return -1;
}

bool Stack::empty()
{
    return stack.size() == 0;

}