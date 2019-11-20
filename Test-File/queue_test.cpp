//
// Created by lvjer on 2019/11/20.
//

#include "queue_test.h"
#include "../1-linear-structure/queue/Queue_Extended.h"

void queue_test() {

    Queue_Extended<int> queue;
    queue.append(10);
    queue.append(10);
    queue.append(10);
    queue.append(10);
    queue.append(10);
    queue.append(10);
    queue.append(10);
    queue.append(10);
    std::cout << queue.size() << std::endl;
    queue.append(10);
    queue.append(10);
    queue.serve();
    queue.serve();
    queue.serve();
    queue.serve();
    queue.serve();
    queue.serve();
    queue.serve();
    queue.serve();
    queue.serve();
    queue.serve();
    queue.append(2);

}