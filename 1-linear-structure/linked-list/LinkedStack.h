//
// Created by lvjer on 2019/11/21.
//

#ifndef UNGEE_DATASTRUCTURES_LINKEDSTACK_H
#define UNGEE_DATASTRUCTURES_LINKEDSTACK_H

#include <iostream>
#include "Node.h"

template<class Stack_entry>
class LinkedStack {
public:
    LinkedStack();

    LinkedStack(const LinkedStack<Stack_entry> &original);

    ~LinkedStack();

    bool empty() const;

    void push(const Stack_entry item);

    void pop();

    void top(Stack_entry &item) const;

    void operator=(const LinkedStack &original);

private:
    Node<Stack_entry> *top_node;
};

template<class Stack_entry>
LinkedStack<Stack_entry>::LinkedStack() {

}

template<class Stack_entry>
bool LinkedStack<Stack_entry>::empty() const {
    return top_node == nullptr;
}

template<class Stack_entry>
void LinkedStack<Stack_entry>::push(const Stack_entry item) {
    auto new_top = new Node<Stack_entry>(item, top_node);
    std::cout << "Insert node to the stack: " << new_top->entry << std::endl;
}

template<class Stack_entry>
void LinkedStack<Stack_entry>::pop() {
    auto old_top = top_node;
    if (empty()) {
        std::cout << "The stack is empty" << std::endl;
        return;
    } else {
        top_node = top_node->next;
        std::cout << "Delete node from the stack: " << old_top->entry << std::endl;
        delete old_top;
        old_top = nullptr;
    }
}

template<class Stack_entry>
void LinkedStack<Stack_entry>::top(Stack_entry &item) const {
    if (empty()) {
        std::cout << "The stack is empty" << std::endl;
        return;
    } else {
        item = top_node->entry;
    }
}

template<class Stack_entry>
LinkedStack<Stack_entry>::~LinkedStack() {
    while (!empty()) {
        pop();
    }
}

template<class Stack_entry>
void LinkedStack<Stack_entry>::operator=(const LinkedStack &original) {
    top_node = original.top_node;
}

template<class Stack_entry>
LinkedStack<Stack_entry>::LinkedStack(const LinkedStack &original) {
    Node<Stack_entry> *new_copy, *original_node = original.top_node;
    if (original_node == nullptr) {
        top_node = nullptr;
    } else {
        new_copy = top_node = new Node<Stack_entry>(original_node->entry);
        while (original_node->next != nullptr) {
            original_node = original_node->next;
            new_copy->next = new Node<Stack_entry>(original_node->entry);
            new_copy = new_copy->next;
        }
    }
}

#endif //UNGEE_DATASTRUCTURES_LINKEDSTACK_H
