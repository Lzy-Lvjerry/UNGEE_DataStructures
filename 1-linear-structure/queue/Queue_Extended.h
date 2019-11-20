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
    return (this->rear + 1) % this->max_size == this->front;
}

template<class Queue_entry>
void Queue_Extended<Queue_entry>::clear() {
    this->cur_size = 0;
    this->rear = 0;
    this->front = 0;
}

template<class Queue_entry>
void Queue_Extended<Queue_entry>::serve_and_retrieve(Queue_entry &item) {
    if (this->empty()) {
        std::cout << "The queue is empty" << std::endl;
    }
}

#endif //UNGEE_DATASTRUCTURES_QUEUE_EXTENDED_H
