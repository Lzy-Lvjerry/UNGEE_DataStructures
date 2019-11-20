//
// Created by lvjer on 2019/11/20.
//
#include "Stack_Extended.h"
#include "stack_exec.h"
void bracket_matching() {
    /*
     * Post: The program has notified the user of any bracket mismatch in the standard input file
     * Uses: The class Stack
     * */

    Stack_Extended<char> openings;
    char symbol;
    bool is_matched = true;
    while (is_matched && (symbol = std::cin.get()) != '\n')
        if (symbol == '{' || symbol == '[' || symbol == '(') {
            if (openings.full()) {
                is_matched = false;
                std::cout << "The stack overflow" << std::endl;
            } else {
                openings.push(symbol);
            }
        }
    if (symbol == '}' || symbol == ']' || symbol == ')') {
        if (openings.empty()) {
            std::cout << "Unmatched closing bracket " << symbol
                      << "detected." << std::endl;
            is_matched = false;
        } else {
            char match;
            openings.top(match);
            openings.pop();
            is_matched = (symbol == '[' && match == ']')
                         || (symbol == '{' && match == '}')
                         || (symbol == '(' && match == ')');
            if (!is_matched) {
                std::cout << "Bad match " << match << symbol << std::endl;
            }
        }
    }
    if (!openings.empty()) {
        std::cout << "Unmatched opening bracket (s) detected." << std::endl;
    }
}