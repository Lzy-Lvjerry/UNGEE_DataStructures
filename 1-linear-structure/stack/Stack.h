//
// Created by lvjer on 2019/11/19.
//

#ifndef UNGEE_DATASTRUCTURES_STACK_H
#define UNGEE_DATASTRUCTURES_STACK_H

#include <iostream>

template<class Stack_entry>
class Stack {
public:
    Stack() {
        std::cout << "Stack Default Constructor" << std::endl;

        max_stack = 10;
        _count = 0;
        _entry = new Stack_entry[max_stack];
    };

    Stack(int max) {
        max_stack = (max > 0) ? max : 10;
        _count = 0;
        _entry = new Stack_entry[max_stack];
    };

    ~Stack() {
        delete[]_entry;
    }

    int max_stack;

    /*
     * Pre: None.
     * Post: If the Stack is not empty, the top of the Stack is removed. If the Stack is
     *       empty, return.
     *
     * */
    void pop();

    /*
     * Pre: None.
     * Post: If the Stack is not full, item is added to the top of the Stack. If the Stack is
     *       full, return.
     * */
    void push(Stack_entry item);

    /*
     * Pre: None.
     * Post: If the Stack is not empty, the top of the Stack is returned in item. If the Stack
     *       is empty, and a warning is printed.
     * */
    void top(Stack_entry &item) const;

    /*
     * Pre: None.
     * Post: If the Stack is empty, true is returned. Otherwise false is returned.
     * */
    bool empty() const;

protected:
    int _count;
    Stack_entry *_entry;
};


template<class Stack_entry>
void Stack<Stack_entry>::pop() {
    if (this->empty()) {
        std::cout << "The Stack is empty" << std::endl;
        return;
    } else {
        std::cout << "Pop out Stack:" << this->_entry[--_count] << std::endl;
    }

}

template<class Stack_entry>
void Stack<Stack_entry>::push(Stack_entry item) {
    if (_count > max_stack) {
        std::cout << "The Stack Overflow" << std::endl;
        return;
    } else {
        _entry[_count++] = item;
        std::cout << "Push in Stack:" << item << std::endl;
    }
}

template<class Stack_entry>
void Stack<Stack_entry>::top(Stack_entry &item) const {
    if (this->empty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        item = _entry[_count - 1];
    }
}

template<class Stack_entry>
bool Stack<Stack_entry>::empty() const {
    return this->_count == 0;
}

#endif //UNGEE_DATASTRUCTURES_STACK_H
