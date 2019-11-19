//
// Created by lvjer on 2019/11/19.
//

#include <stack>
#include <iostream>

void stack_STL() {
/*
 * Pre: The user supplies an integer n and n decimal numbers
 * Post: The numbers are printed in reverse order.
 * Uses: The STL class stack and ite methods
 *
 * */
    int n;
    double item;
    std::stack<double> numbers;
    std::cout << "Type in an integer n followed by n decimal numbers." << std::endl
              << "The numbers will be printed in reverse order." << std::endl;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> item;
        numbers.push(item);

    }
    std::cout << std::endl << std::endl;
    while (!numbers.empty()) {
        std::cout << numbers.top() << std::endl;
        numbers.pop();
    }
    std::cout << std::endl;

}