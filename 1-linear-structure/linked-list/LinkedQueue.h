//
// Created by lvjer on 2019/11/21.
//

#ifndef UNGEE_DATASTRUCTURES_LINKEDQUEUE_H
#define UNGEE_DATASTRUCTURES_LINKEDQUEUE_H

#include "Node.h"

template<class Queue_entry>
class LinkedQueue {
public:
    LinkedQueue();

    LinkedQueue(const LinkedQueue<Queue_entry> &original);

    ~LinkedQueue();

    void append(const Queue_entry item);

    void serve();

    bool empty() const;

    void retrieve(Queue_entry &item);


private:
    Node<Queue_entry> *front, *rear;
};

template<class Queue_entry>
LinkedQueue<Queue_entry>::LinkedQueue() {

}

template<class Queue_entry>
LinkedQueue<Queue_entry>::LinkedQueue(const LinkedQueue<Queue_entry> &original) {

}

template<class Queue_entry>
LinkedQueue<Queue_entry>::~LinkedQueue() {

}

template<class Queue_entry>
void LinkedQueue<Queue_entry>::append(const Queue_entry item) {

}

template<class Queue_entry>
void LinkedQueue<Queue_entry>::serve() {

}

template<class Queue_entry>
bool LinkedQueue<Queue_entry>::empty() const {
    return false;
}

template<class Queue_entry>
void LinkedQueue<Queue_entry>::retrieve(Queue_entry &item) {

}

#endif //UNGEE_DATASTRUCTURES_LINKEDQUEUE_H
