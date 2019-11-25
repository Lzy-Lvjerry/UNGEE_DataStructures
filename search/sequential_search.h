//
// Created by lvjer on 2019/11/25.
//

#ifndef UNGEE_DATASTRUCTURES_SEQUENTIAL_SEARCH_H
#define UNGEE_DATASTRUCTURES_SEQUENTIAL_SEARCH_H

#include "../1-linear-structure/list/List.h"

void sequential_search(const List<int> &the_list,
                       const int &target, int &position) {
    int s = the_list.size();
    int data;

    for (position = 0; position < s; ++position) {
        the_list.retrieve(data, position);
        if (data == target) {
            std::cout << "Found success"<<std::endl;
            return;
        }
    }
    std::cout <<"No found target"<<std::endl;
}

#endif //UNGEE_DATASTRUCTURES_SEQUENTIAL_SEARCH_H
