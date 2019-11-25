//
// Created by lvjer on 2019/11/25.
//

#ifndef UNGEE_DATASTRUCTURES_BINARY_SEARCH_H
#define UNGEE_DATASTRUCTURES_BINARY_SEARCH_H

#include "../1-linear-structure/list/Ordered_List.h"

void recursive_binary_1(const Order_List &the_list, const int &target,
                        int bottom, int top, int &position) {
    int data;
    if(bottom<top){
        int mid = (bottom+top)/2;
        the_list.retrieve(data,mid);
        if (data<target){
            return recursive_binary_1(the_list,target,mid+1,top,position);
        } else{
            return recursive_binary_1(the_list,target,bottom,mid,position);
        }
    }
    else if(top<bottom){
        std::cout << "not present"<<std::endl;
        return;
    } else{
        position = bottom;
        the_list.retrieve(data,bottom);
        if (data==target){
            std::cout <<"Success found target"<<std::endl;
        } else{
            std::cout << "Not found"<<std::endl;
        }
    }

}

#endif //UNGEE_DATASTRUCTURES_BINARY_SEARCH_H
