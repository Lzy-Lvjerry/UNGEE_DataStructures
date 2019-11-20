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
        _maxSize = 10;
        _curSize = 0;
        _entry = new Queue_entry[_maxSize];
        _rear = 0;
        _front = 0;
    }

    ~Queue() {
        delete[]_entry;
    }

    void append(const Queue_entry x);

    void serve();

    int size();

    void retriever(Queue_entry &x) const;

    bool empty();

protected:
    Queue_entry *_entry;
    int _maxSize;
    int _curSize;
    int _front;
    int _rear;
};

template<class Queue_entry>
void Queue<Queue_entry>::append(const Queue_entry x) {
    if ((_rear + 1) % _maxSize == _front) {
        std::cout << "The queue overflow" << std::endl;
        return;
    } else {
        std::cout << "append: " << x << std::endl;
        _entry[_rear] = x;
        _rear = (_rear + 1) % _maxSize;
        _curSize++;
    }
}

template<class Queue_entry>
void Queue<Queue_entry>::serve() {
    if (empty()) {
        std::cout << "The queue underflow" << std::endl;
        return;
    } else {
        std::cout << "serve: " << _entry[_front] << std::endl;
        _front = (_front + 1) % _maxSize;
        _curSize--;
    }
}

template<class Queue_entry>
int Queue<Queue_entry>::size() {
    return _curSize;
}

template<class Queue_entry>
void Queue<Queue_entry>::retriever(Queue_entry &x) const {
    if (empty()) {
        std::cout << "The stack is empty" << std::endl;
    } else {
        x = _entry[_front];
    }
}

template<class Queue_entry>
bool Queue<Queue_entry>::empty() {
    return _front == _rear;
}

#endif //UNGEE_DATASTRUCTURES_QUEUE_H
