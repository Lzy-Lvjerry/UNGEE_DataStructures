//
// Created by lvjer on 2019/11/19.
//

#ifndef UNGEE_DATASTRUCTURES_STACK_EXTENDED_H
#define UNGEE_DATASTRUCTURES_STACK_EXTENDED_H

#include "Stack.h"

template<class Stack_entry>
class Stack_Extended : public Stack<Stack_entry> {
public:
    Stack_Extended();

    Stack_Extended(int max);

    // Reset the stack to be empty
    void clear();

    // If the stack is full, return true;else return false.
    bool full() const;

    // Return the number of entries in the stack.
    int size() const;

};

template<typename Stack_entry>
Stack_Extended<Stack_entry>::Stack_Extended() :Stack<Stack_entry>() {
    std::cout << "Extended Stack Default Constructor" << std::endl;
}

template<typename Stack_entry>
Stack_Extended<Stack_entry>::Stack_Extended(int max):Stack<Stack_entry>(max) {}

template<typename Stack_entry>
void Stack_Extended<Stack_entry>::clear() {
    this->count = 0;
}

template<typename Stack_entry>
bool Stack_Extended<Stack_entry>::full() const {
    return this->count > this->max_stack;
}

template<typename Stack_entry>
int Stack_Extended<Stack_entry>::size() const {
    return this->count;
}

#endif //UNGEE_DATASTRUCTURES_STACK_EXTENDED_H
