//
// Created by lvjer on 2019/11/20.
//

#ifndef UNGEE_DATASTRUCTURES_QUEUE_EXTENDED_H
#define UNGEE_DATASTRUCTURES_QUEUE_EXTENDED_H

#include "Queue.h"

template<class Queue_entry>
class Queue_Extended : public Queue<Queue_entry> {
public:
    bool full() const;

    void clear();

    void serve_and_retrieve(Queue_entry &item);

protected:
};


template<class Queue_entry>
bool Queue_Extended<Queue_entry>::full() const {
    return (this->_rear + 1) % this->_maxSize == this->_front;
}

template<class Queue_entry>
void Queue_Extended<Queue_entry>::clear() {
    this->_curSize = 0;
    this->_rear = 0;
    this->_front = 0;
}

template<class Queue_entry>
void Queue_Extended<Queue_entry>::serve_and_retrieve(Queue_entry &item) {
    if (this->empty()) {
        std::cout << "The queue is empty" << std::endl;
    }
}

#endif //UNGEE_DATASTRUCTURES_QUEUE_EXTENDED_H
