//
// Created by alex on 9/12/17.
//

#ifndef STACKED_STACK_H
#define STACKED_STACK_H

#include <vector>

struct Stack
{
    std::vector<int> stack;
    int i;

    Stack();

    int nextElement();
    int top();
    bool empty();
};


#endif //STACKED_STACK_H
