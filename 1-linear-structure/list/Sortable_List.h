//
// Created by lvjer on 2019/11/26.
//

#ifndef UNGEE_DATASTRUCTURES_SORTABLE_LIST_H
#define UNGEE_DATASTRUCTURES_SORTABLE_LIST_H

#include "List.h"

template<class Record>
class Sortable_List : public List<Record> {
public:
    void insertion_sort();

    void selection_sort();

private:
    int max_key(int low, int high);

    void swap(int low, int high);
};

template<class Record>
void Sortable_List<Record>::insertion_sort() {
    int first_unsorted;
    int position;
    Record current;
    for (first_unsorted = 1; first_unsorted < this->count; ++first_unsorted) {
        if (this->entry[first_unsorted] < this->entry[first_unsorted - 1]) {
            position = first_unsorted;
            current = this->entry[first_unsorted];
            do {
                this->entry[position] = this->entry[position - 1];
                position--;
            } while (position > 0 && this->entry[position - 1] > current);
            this->entry[position] = current;
        }
    }
}

template<class Record>
void Sortable_List<Record>::selection_sort() {
    int max;
    for (int position = this->count - 1; position > 0; --position) {
        max = max_key(0, position);
        swap(max, position);
    }

}

template<class Record>
int Sortable_List<Record>::max_key(int low, int high) {
    int largest, current;
    largest = low;
    for (current = low + 1; current <= high; ++current) {
        if (this->entry[largest] < this->entry[current]) {
            largest = current;
        }
    }
    return largest;
}

template<class Record>
void Sortable_List<Record>::swap(int low, int high) {
    Record temp;
    temp = this->entry[low];
    this->entry[low] = this->entry[high];
    this->entry[high] = temp;
}

#endif //UNGEE_DATASTRUCTURES_SORTABLE_LIST_H
