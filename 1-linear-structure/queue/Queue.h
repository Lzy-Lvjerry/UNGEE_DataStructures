//
// Created by lvjer on 2019/11/20.
//

#ifndef UNGEE_DATASTRUCTURES_QUEUE_H
#define UNGEE_DATASTRUCTURES_QUEUE_H

#include <iostream>

template<class Queue_entry>
class Queue {

public:
    Queue() {
        max_size = 10;
        cur_size = 0;
        entry = new Queue_entry[max_size];
        rear = 0;
        front = 0;
    }

    ~Queue() {
        delete[]entry;
    }

    void append(const Queue_entry x);

    void serve();

    int size();

    void retriever(Queue_entry &x) const;

    bool empty();

protected:
    Queue_entry *entry;
    int max_size;
    int cur_size;
    int front;
    int rear;
};

template<class Queue_entry>
void Queue<Queue_entry>::append(const Queue_entry x) {
    if ((rear + 1) % max_size == front) {
        std::cout << "The queue overflow" << std::endl;
        return;
    } else {
        std::cout << "append: " << x << std::endl;
        entry[rear] = x;
        rear = (rear + 1) % max_size;
        cur_size++;
    }
}

template<class Queue_entry>
void Queue<Queue_entry>::serve() {
    if (empty()) {
        std::cout << "The queue underflow" << std::endl;
        return;
    } else {
        std::cout << "serve: " << entry[front] << std::endl;
        front = (front + 1) % max_size;
        cur_size--;
    }
}

template<class Queue_entry>
int Queue<Queue_entry>::size() {
    return cur_size;
}

template<class Queue_entry>
void Queue<Queue_entry>::retriever(Queue_entry &x) const {
    if (empty()) {
        std::cout << "The stack is empty" << std::endl;
    } else {
        x = entry[front];
    }
}

template<class Queue_entry>
bool Queue<Queue_entry>::empty() {
    return front == rear;
}

#endif //UNGEE_DATASTRUCTURES_QUEUE_H
