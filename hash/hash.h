//
// Created by lvjer on 2019/12/7.
//

#ifndef UNGEE_DATASTRUCTURES_HASH_H
#define UNGEE_DATASTRUCTURES_HASH_H

#include "Key.h"

const int hash_size = 997;

template<class Record>
class Hash_table {
public:
    Hash_table();

    void clear();

    void insert(const Record &new_entry);

    void retrieve(const Key &target, Record &found) const;

private:
    Record table[hash_size];
};

int hash(const Key &target) {
    int value = 0;
    for (int position = 0; position < 8; ++position) {
        value = 4 * value + target.key_letter(position);
    }
    return value % hash_size;
}

template<class Record>
Hash_table<Record>::Hash_table() {

}

template<class Record>
void Hash_table<Record>::clear() {

}

template<class Record>
void Hash_table<Record>::insert(const Record &new_entry) {
    int probe_count,
            increment,
            probe;
    Key null;
    null.make_blank();
    probe = hash(new_entry);
    probe_count = 0;
    increment = 1;
    while (table[probe] != null &&
           table[probe] != new_entry &&
           probe_count < (hash_size + 1) / 2) {
        probe_count++;
        probe = (probe + increment) % hash_size;
        increment += 2;
    }
    if (table[probe] == null) {
        table[probe] = new_entry;
    } else if (table[probe] == new_entry) {
        std::cout << "duplicate error" << std::endl;
    } else {
        std::cout << "overflow" << std::endl;
    }
}

template<class Record>
void Hash_table<Record>::retrieve(const Key &target, Record &found) const {

}

#endif //UNGEE_DATASTRUCTURES_HASH_H
