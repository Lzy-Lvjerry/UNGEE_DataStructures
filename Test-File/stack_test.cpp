//
// Created by lvjer on 2019/11/19.
//

#include "../1-linear-structure/stack/Stack_Extended.h"
#include "../1-linear-structure/stack/stack_exec.h"
#include <iostream>

void stack_test() {

    Stack_Extended<int> mystack(10);
    mystack.push(5);
    mystack.push(10);
    mystack.push(10);
    mystack.push(10);
    mystack.push(10);
    mystack.push(10);
    mystack.push(10);
    mystack.push(10);
    mystack.push(10);
    mystack.push(10);
    mystack.push(10);
    mystack.push(10);
    mystack.pop();
    mystack.pop();
    mystack.push(2);
    int top;
    mystack.top(top);
    std::cout << "Stack top:" << top << std::endl;
    std::cout <<"Stack size:"<<mystack.size()<<std::endl;
}

void stack_bracket_matching(){

    bracket_matching();
}
