//
// Created by lvjer on 2019/11/23.
//

#ifndef UNGEE_DATASTRUCTURES_LINK_LIST_H
#define UNGEE_DATASTRUCTURES_LINK_LIST_H

#include <iostream>

template<class Node_entry>
struct List_Node {
    Node_entry entry;
    List_Node<Node_entry> *next;

    List_Node();

    List_Node(Node_entry, List_Node<Node_entry> *link = nullptr);
};

template<class List_entry>
class Link_List {
public:
    Link_List();

    ~Link_List();

    Link_List(const Link_List<List_entry> &copy);

    void operator=(const Link_List<List_entry> &copy);

protected:
    int count;
    List_Node<List_entry> *head;

    List_Node<List_entry> *set_position(int position) const;
};

template<class Node_entry>
List_Node<Node_entry>::List_Node() {

}

template<class Node_entry>
List_Node<Node_entry>::List_Node(Node_entry, List_Node<Node_entry> *link) {

}

template<class List_entry>
Link_List<List_entry>::Link_List() {

}

template<class List_entry>
Link_List<List_entry>::~Link_List() {

}

template<class List_entry>
Link_List<List_entry>::Link_List(const Link_List<List_entry> &copy) {

}

template<class List_entry>
void Link_List<List_entry>::operator=(const Link_List<List_entry> &copy) {

}

template<class List_entry>
List_Node<List_entry> *Link_List<List_entry>::set_position(int position) const {
    List_Node<List_entry> *q = head;
    for (int i = 0; i < position && q != nullptr; ++i) {
        q = q->next;
    }
    return q;
}

#endif //UNGEE_DATASTRUCTURES_LINK_LIST_H
