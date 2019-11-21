//
// Created by lvjer on 2019/11/21.
//

#ifndef UNGEE_DATASTRUCTURES_NODE_H
#define UNGEE_DATASTRUCTURES_NODE_H

template <typename Node_entry>
struct Node{
    Node_entry entry;
    Node *next;
    Node();
    Node(Node_entry item,Node *add_on = nullptr);
};

template<typename Node_entry>
Node<Node_entry>::Node() {
    next = nullptr;
}

template<typename Node_entry>
Node<Node_entry>::Node(Node_entry item, Node *add_on) {
    entry = item;
    next = add_on;
}

#endif //UNGEE_DATASTRUCTURES_NODE_H
