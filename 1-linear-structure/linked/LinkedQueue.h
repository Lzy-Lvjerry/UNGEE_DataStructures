//
// Created by lvjer on 2019/11/21.
//

#ifndef UNGEE_DATASTRUCTURES_LINKEDQUEUE_H
#define UNGEE_DATASTRUCTURES_LINKEDQUEUE_H

#include <iostream>
#include "Node.h"

template<class Queue_entry>
class LinkedQueue {
public:
    LinkedQueue();

    LinkedQueue(const LinkedQueue<Queue_entry> &original);

    ~LinkedQueue();

    void operator=(const LinkedQueue<Queue_entry> &original);

    void append(const Queue_entry &item);

    void serve();

    inline bool empty() const;

    void clear();

    int size() const;

    void retrieve(Queue_entry &item);

    void serve_and_retrieve(Queue_entry &item);

private:
    Node<Queue_entry> *front, *rear;
};

template<class Queue_entry>
LinkedQueue<Queue_entry>::LinkedQueue(const LinkedQueue<Queue_entry> &original) {
    if (original.empty()) {
        front = nullptr;
        rear = nullptr;
    }
    Node<Queue_entry> *original_temp = original.front;
    rear = front = new Node<Queue_entry>(original.front->entry);
    while ((original_temp = original_temp->next) != nullptr) {
        rear = rear->next;
        rear = new Node<Queue_entry>(original_temp->entry);
    }
}

template<class Queue_entry>
LinkedQueue<Queue_entry>::LinkedQueue() :front(nullptr), rear(nullptr) {
}


template<class Queue_entry>
LinkedQueue<Queue_entry>::~LinkedQueue() {
    while (!empty()) {
        serve();
    }
}

template<class Queue_entry>
void LinkedQueue<Queue_entry>::append(const Queue_entry &item) {
    auto new_rear = new Node<Queue_entry>(item);
    if (empty()) {
        rear = front = new_rear;
    } else {
        rear->next = new_rear;
        rear = new_rear;
    }
}

template<class Queue_entry>
void LinkedQueue<Queue_entry>::serve() {
    if (empty()) {
        std::cout << "Queue Serve Error: The queue is empty" << std::endl;
    } else {
        Node<Queue_entry> *old_front = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete old_front;
    }
}

template<class Queue_entry>
bool LinkedQueue<Queue_entry>::empty() const {
    return (front == nullptr && rear == nullptr);
}

template<class Queue_entry>
void LinkedQueue<Queue_entry>::retrieve(Queue_entry &item) {
    if (empty()) {
        std::cout << "The queue is empty" << std::endl;
    } else {
        item = front->entry;
    }
}

template<class Queue_entry>
void LinkedQueue<Queue_entry>::clear() {
    while (!empty()) {
        serve();
    }
}

template<class Queue_entry>
int LinkedQueue<Queue_entry>::size() const {
    int count = 0;
    Node<Queue_entry> *temp = front;
    while (temp != nullptr) {
        temp = temp->next;
        count++;
    }
    return 0;
}

template<class Queue_entry>
void LinkedQueue<Queue_entry>::serve_and_retrieve(Queue_entry &item) {
    if (empty()) {
        std::cout << "The queue is empty" << std::endl;
    } else {
        item = front->entry;
        serve();
    }
}

template<class Queue_entry>
void LinkedQueue<Queue_entry>::operator=(const LinkedQueue<Queue_entry> &original) {
    front = original.front;
    rear = original.rear;
}

#endif //UNGEE_DATASTRUCTURES_LINKEDQUEUE_H
