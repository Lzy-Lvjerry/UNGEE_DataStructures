//
// Created by lvjer on 2019/12/4.
//

#ifndef UNGEE_DATASTRUCTURES_B_TREE_H
#define UNGEE_DATASTRUCTURES_B_TREE_H

#include <iostream>

template<class Record, int order>
struct B_node {
    int count; // 该结点中的记录数

    Record data[order - 1];
    B_node<Record, order> *branch[order];

    B_node();
};

template<class Record, int order>
class B_tree {
public:
    bool search_tree(Record &target);

    void insert(const Record &new_entry);

private:
    B_node<Record, order> *root;

    bool search_node(B_node<Record, order> *current, const Record &target, int &position);

    bool recursive_search_tree(B_node<Record, order> *current, Record &target);

    bool push_down(B_node<Record, order> *current,
                   const Record &new_entry,
                   Record &median,
                   B_node<Record, order> *&right_branch);

    void push_in(B_node<Record, order> *current,
                 const Record &entry, B_node<Record, order> *right_branch, int position);

    void split_node(B_node<Record, order> *current,
                    const Record &extra_entry,
                    B_node<Record, order> *extra_brach,
                    int position,
                    B_node<Record, order> *right_half,
                    Record &median);


};

template<class Record, int order>
bool B_tree<Record, order>::search_tree(Record &target) {
    return recursive_search_tree(root, target);
}

template<class Record, int order>
bool B_tree<Record, order>::recursive_search_tree(B_node<Record, order> *current, Record &target) {
    int position;
    bool result = false;
    if (current != nullptr) {
        result = search_node(current, target, position);
        if (!result) {
            result = recursive_search_tree(current->branch[position], target);
        } else {
            target = current->data[position];
        }
    }
    return result;
}

template<class Record, int order>
bool B_tree<Record, order>::search_node(B_node<Record, order> *current, const Record &target, int &position) {
    position = 0;
    while (position < current->count && target > current->data[position]) {
        position++;
    }
    return position < current->count && target == current->data[position];
}

template<class Record, int order>
void B_tree<Record, order>::insert(const Record &new_entry) {
    Record median;
    B_node<Record, order> *right_branch, *new_root;
//    false == overflow
    bool result = push_down(root, new_entry, median, right_branch);
    if (!result) {
        new_root = new B_node<Record, order>;
        new_root->count = 1;
        new_root->data[0] = median;
        new_root->branch[0] = root;
        new_root->branch[1] = right_branch;
        root = new_root;
        result = true;
    }
}

template<class Record, int order>
bool B_tree<Record, order>::push_down(B_node<Record, order> *current, const Record &new_entry, Record &median,
                                      B_node<Record, order> *&right_branch) {

    bool result;
    int position;
    if (current == nullptr) {
        median = new_entry;
        right_branch = nullptr;
        result = false;
    } else {
        if (search_node((current, new_entry, position))) {
            std::cout << "duplicate_error" << std::endl;
        } else {
            Record extra_entry;
            B_node<Record, order> *extra_branch;
            result = push_down(current->branch[position], new_entry,
                               extra_entry, extra_branch);
            if (!result) {
                if (current->count < order - 1) {
                    result = true;
                    push_in(current, extra_entry, extra_branch, position);
                } else {
                    split_node(current, extra_entry, extra_branch, position,
                               right_branch, median);
                }
            }
        }
    }
    return result;
}

template<class Record, int order>
void
B_tree<Record, order>::push_in(B_node<Record, order> *current, const Record &entry, B_node<Record, order> *right_branch,
                               int position) {
    for (int i = current->count; i > position; --i) {
        current->data[i] = current->data[i - 1];
        current->branch[i + 1] = current->branch[i];
    }
    current->data[position] = entry;
    current->branch[position + 1] = right_branch;
    current->count++;
}

template<class Record, int order>
void
B_tree<Record, order>::split_node(B_node<Record, order> *current, const Record &extra_entry,
                                  B_node<Record, order> *extra_branch, int position, B_node<Record, order> *right_half,
                                  Record &median) {
    right_half = new B_node<Record, order>;
    int mid = order / 2;
    if (position <= mid) {
        for (int i = mid; i < order - 1; ++i) {
            right_half->data[i - mid] = current->data[i];
            right_half->branch[i + 1 - mid] = current->branch[i + 1];
        }
        current->count = mid;
        right_half->count = order - 1 - mid;
        push_in(current, extra_entry, extra_branch, position);
    } else {
        mid++;
        for (int i = mid; i < order - 1; ++i) {
            right_half->data[i - mid] = current->data[i];
            right_half->branch[i + 1 - mid] = current->branch[i + 1];
        }
        current->count = mid;
        right_half->count = order - 1 - mid;
        push_in(right_half, extra_entry, extra_branch, position - mid);

    }
    median = current->data[current->count - 1];
    right_half->branch[0] = current->branch[current->count];
    current->count--;
}

#endif //UNGEE_DATASTRUCTURES_B_TREE_H
