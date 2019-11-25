//
// Created by lvjer on 2019/11/25.
//

#ifndef UNGEE_DATASTRUCTURES_ORDER_LIST_H
#define UNGEE_DATASTRUCTURES_ORDER_LIST_H

#include"List.h"

class Order_List : public List<int> {
public:
    Order_List();

    void insert(const int &data);

    void insert(int &data, int position);

    void replace(const int &data, int position);
};

Order_List::Order_List() {

}

void Order_List::insert(const int &data) {
    int s = size();
    int position;
    int list_data;
    for (position = 0; position < s; ++position) {
        retrieve(list_data, position);
        if (data >= list_data)break;
    }
    return List<int>::insert(position, data);
}

void Order_List::insert(int &data, int position) {
    int list_data;
    if (position > 0) {
        retrieve(list_data, position - 1);
        if (data < list_data) {
            std::cout << "insert fail" << std::endl;
            return;
        }
    }
    if (position < size()) {
        retrieve(list_data, position);
        if (data > list_data) {
            std::cout << "insert fail" << std::endl;
            return;
        }
    }
    return List<int>::insert(position, data);
}

void Order_List::replace(const int &data, int position) {

}

#endif //UNGEE_DATASTRUCTURES_ORDER_LIST_H
