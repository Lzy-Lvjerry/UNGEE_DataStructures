//
// Created by lvjer on 2019/12/9.
//

#ifndef UNGEE_DATASTRUCTURES_FACTORIAL_H
#define UNGEE_DATASTRUCTURES_FACTORIAL_H

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int factorial_2(int n) {
    int count, product = 1;
    for (count = 1; count <= n; ++count) {
        product *= count;
    }
    return product;
}

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return factorial(n - 1) + fibonacci(n - 2);
    }
}

int fibonacci_2(int n){
    int last_but_one;
    int last_value;
    int current = 0;
    if(n<=0){
        return 0;
    } else if (n==1){
        return 1;
    } else{
        last_but_one = 0;
        last_value =1;
        for (int i = 2; i <= n; ++i) {
            current = last_but_one+last_value;
            last_but_one = last_value;
            last_value = current;
        }
        return current;
    }
}


#endif //UNGEE_DATASTRUCTURES_FACTORIAL_H
