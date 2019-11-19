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
        count = 0;
        entry = new Stack_entry[max_stack];
    };

    Stack(int max) {
        max_stack = (max > 0) ? max : 10;
        count = 0;
        entry = new Stack_entry[max_stack];
    };

    ~Stack() {
        delete[]entry;
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
    Stack_entry top() const;

    /*
     * Pre: None.
     * Post: If the Stack is empty, true is returned. Otherwise false is returned.
     * */
    bool empty() const;

protected:
    int count;
    Stack_entry *entry;
};


template<class Stack_entry>
void Stack<Stack_entry>::pop() {
    if (this->empty()) {
        std::cout << "The Stack is empty" << std::endl;
        return;
    } else {
        std::cout << "Pop out Stack:" << this->entry[--count] << std::endl;
    }

}

template<class Stack_entry>
void Stack<Stack_entry>::push(Stack_entry item) {
    if (count > max_stack) {
        std::cout << "The Stack Overflow" << std::endl;
        return;
    } else {
        entry[count++] = item;
        std::cout << "Push in Stack:" << item << std::endl;
    }
}

template<class Stack_entry>
Stack_entry Stack<Stack_entry>::top() const {
    if (this->empty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        return entry[count - 1];
    }
}

template<class Stack_entry>
bool Stack<Stack_entry>::empty() const {
    return this->count == 0;
}

#endif //UNGEE_DATASTRUCTURES_STACK_H
