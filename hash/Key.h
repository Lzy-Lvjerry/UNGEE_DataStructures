//
// Created by lvjer on 2019/12/7.
//

#ifndef UNGEE_DATASTRUCTURES_KEY_H
#define UNGEE_DATASTRUCTURES_KEY_H

#include "../1-linear-structure/list/String.h"
class Key:public String{
public:
    char key_letter(int position)const;
    void make_blank();

};
#endif //UNGEE_DATASTRUCTURES_KEY_H
