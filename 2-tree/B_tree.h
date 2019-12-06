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

    void remove(const Record &target);

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
                    B_node<Record, order> *extra_branch,
                    int position,
                    B_node<Record, order> *right_half,
                    Record &median);

    void recursive_remove(B_node<Record, order> *current, const Record &target);

    void remove_data(B_node<Record, order> *current, int position);

    void copy_in_predecessor(B_node<Record, order> *current, int position);

    void restore(B_node<Record, order> *current, int position);

    void move_left(B_node<Record, order> *current, int position);

    void move_right(B_node<Record, order> *current, int position);

    void combine(B_node<Record, order> *current, int position);
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
    }
}

template<class Record, int order>
bool B_tree<Record, order>::push_down(B_node<Record, order> *current, const Record &new_entry, Record &median,
                                      B_node<Record, order> *&right_branch) {

    bool result = true;
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

template<class Record, int order>
void B_tree<Record, order>::remove(const Record &target) {
    recursive_remove(root, target);
    if (root != nullptr && root->count == 0) {
        B_node<Record, order> *old_root = root;
        root = root->branch[0];
        delete old_root;
    }
}

template<class Record, int order>
void B_tree<Record, order>::recursive_remove(B_node<Record, order> *current, const Record &target) {
    int position;
    if (current == nullptr) {
        std::cout << "not_present" << std::endl;
    } else {
        if (search_node(current, target, position)) {
            if (current->branch[position] != nullptr) {
                copy_in_predecessor(current, position);
                recursive_remove(current->branch[position,
                        current->data[position]]);
            } else {
                remove_data(current, position);
            }
        } else {
            recursive_remove(current->branch[position, target]);
        }
        if (current->branch[position] != nullptr) {
            if (current->branch[position]->count < (order - 1) / 2) {
                restore(current, position);
            }
        }
    }
}

template<class Record, int order>
void B_tree<Record, order>::remove_data(B_node<Record, order> *current, int position) {
    for (int i = position; i < current->count - 1; ++i) {
        current->data[i] = current->data[i + 1];
    }
    current->count--;
}

template<class Record, int order>
void B_tree<Record, order>::copy_in_predecessor(B_node<Record, order> *current, int position) {
    B_node<Record, order> *leaf = current->branch[position];
    while (leaf->branch[leaf->count] != nullptr) {
        leaf = leaf->branch[leaf->count];
    }
    current->data[position] = leaf->data[leaf->count - 1];
}

template<class Record, int order>
void B_tree<Record, order>::restore(B_node<Record, order> *current, int position) {
    if (position == current->count) {
        if (current->branch[position - 1]->count > (order - 1) / 2) {
            move_left(current, 1);
        } else {
            combine(current, 1);
        }
    } else {
        if (current->branch[position - 1]->count > (order - 1) / 2) {
            move_right(current, position - 1);
        } else if (current->branch[position + 1]->count > (order - 1) / 2) {
            move_left(current, position + 1);
        } else {
            combine(current, position);
        }
    }
}

template<class Record, int order>
void B_tree<Record, order>::move_left(B_node<Record, order> *current, int position) {
    B_node<Record, order> *left_branch = current->branch[position - 1],
            *right_branch = current->branch[position];
    left_branch->data[left_branch->count] = current->data[position - 1];
    left_branch->branch[++left_branch->count] = right_branch->branch[0];
    current->data[position - 1] = right_branch->data[0];
    right_branch->count--;
    for (int i = 0; i < right_branch->count; ++i) {
        right_branch->data[i] = right_branch->data[i + 1];
        right_branch->branch[i] = right_branch->branch[i + 1];
    }
    right_branch->branch[right_branch->count] =
            right_branch->branch[right_branch->count + 1];
}

template<class Record, int order>
void B_tree<Record, order>::move_right(B_node<Record, order> *current, int position) {
    B_node<Record, order> *right_branch = current->branch[position + 1],
            *left_branch = current->branch[position];
    right_branch->branch[right_branch->count + 1] =
            right_branch->branch[right_branch->count];
    for (int i = right_branch->count; i > 0; --i) {
        right_branch->data[i] = right_branch->data[i - 1];
        right_branch->branch[i] = right_branch->branch[i - 1];

    }
    right_branch->count++;
    right_branch->data[0] = current->data[position];
    right_branch->branch[0] = left_branch->branch[left_branch->count--];
    current->data[position] = left_branch->data[left_branch->count];
}

template<class Record, int order>
void B_tree<Record, order>::combine(B_node<Record, order> *current, int position) {
    B_node<Record, order> *left_branch = current->branch[position - 1],
            *right_branch = current->branch[position];
    left_branch->data[left_branch->count] = current->data[position - 1];
    left_branch->branch[++left_branch->count] = right_branch->branch[0];
    for (int i = 0; i < right_branch->count; ++i) {
        left_branch->data[left_branch->count] = right_branch->data[i];
        left_branch->branch[++left_branch->count] =
                right_branch->branch[i + 1];
    }
    current->count--;
    for (int i = position; i < current->count; ++i) {
        current->data[i] = current->data[i + 1];
        current->branch[i + 1] = current->branch[i + 2];
    }
    delete right_branch;
}

#endif //UNGEE_DATASTRUCTURES_B_TREE_H
