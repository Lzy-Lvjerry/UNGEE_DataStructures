//
// Created by lvjer on 2019/11/23.
//

#ifndef UNGEE_DATASTRUCTURES_LIST_H
#define UNGEE_DATASTRUCTURES_LIST_H

#include <iostream>

template<class List_entry>
class List {
public:
    List();

    ~List();

    void construct();

    bool empty() const;

    bool full() const;

    int size() const;

    void clear();

    void insert(int position, const List_entry &x);

    void remove(int position);

    void retrieve(List_entry &x, int position) const;

    void replace(List_entry &x, int position);

    void traverse(void (*visit)(List_entry &));

private:
    int count;
    int max_size;
    List_entry *entry;
};

template<class List_entry>
List<List_entry>::List() {
    count = 0;
    max_size = 10;
    entry = new List_entry[10];
}

template<class List_entry>
List<List_entry>::~List() {
    delete[]entry;
}

template<class List_entry>
void List<List_entry>::construct() {

}

template<class List_entry>
bool List<List_entry>::empty() const {
    return count == 0;
}

template<class List_entry>
bool List<List_entry>::full() const {
    return count == max_size;
}

template<class List_entry>
int List<List_entry>::size() const {
    return count;
}

template<class List_entry>
void List<List_entry>::clear() {
    std::cout << "clear the list" << std::endl;
    count = 0;
}

template<class List_entry>
void List<List_entry>::insert(int position, const List_entry &x) {
    if (full()) {
        std::cout << "The list is full" << std::endl;
        return;
    }
    if (position < 0 || position > count) {
        std::cout << "Position range error" << std::endl;
        return;
    }
    for (int i = count - 1; i <= position; --i) {
        entry[i + 1] = entry[i];
    }
    entry[position] = x;
    count++;
    std::cout << "Insert " << x << "to position " << position << std::endl;

}

template<class List_entry>
void List<List_entry>::remove(int position) {
    if (empty()) {
        std::cout << "The list is empty" << std::endl;
    }
    if (position < 0 || position > count) {
        std::cout << "Position range error" << std::endl;
    }
    List_entry x = entry[position - 1];
    for (int i = position - 1; i < count - 1; ++i) {
        entry[i] = entry[i + 1];
    }
    count--;
    std::cout << "remove " << x << std::endl;
}

template<class List_entry>
void List<List_entry>::retrieve(List_entry &x, int position) const {
    x = entry[position - 1];
}

template<class List_entry>
void List<List_entry>::replace(List_entry &x, int position) {
    std::cout << entry[position - 1] << "replace to " << x << std::endl;
    entry[position - 1] = x;
}

template<class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &)) {
    for (int i = 0; i < count; ++i) {
        (*visit)(entry[i]);
    }
}

#endif //UNGEE_DATASTRUCTURES_LIST_H
