//
// Created by lvjer on 2019/12/9.
//

#ifndef UNGEE_DATASTRUCTURES_EIGHT_QUEENS_H
#define UNGEE_DATASTRUCTURES_EIGHT_QUEENS_H

#include <iostream>

const int max_board = 30;

class Queens {
public:
    Queens(int size);

    bool is_solved() const;

    void print() const;

    bool unguarded(int col) const;

    void insert(int col);

    void remove(int col);

    int board_size; // 目标的棋子数量、棋盘的总行数
private:
    int count; // 当前的皇后数量与首个无皇后的行坐标
    bool col_free[max_board - 1];
    bool upward_free[2 * max_board - 1]; // 左下到右上的对角线
    bool downward_free[2 * max_board - 1]; // 左上到右下的对角线
    int queen_in_row[max_board];
};

Queens::Queens(int size) {
    board_size = size;
    count = 0;
    for (int i = 0; i < board_size; ++i) {
        col_free[i] = true;
    }
    for (int j = 0; j < (2 * board_size - 1); ++j) {
        upward_free[j] = true;
    }
    for (int k = 0; k < (2 * board_size - 1); ++k) {
        downward_free[k] = true;
    }
}

bool Queens::is_solved() const {
    return count == board_size;
}

void Queens::print() const {
    int i, j;
    for (i = 0; i < board_size; ++i) {
        std::cout << "--";
    }
    std::cout << "--\n";
    for (i = 0; i < board_size; ++i) {
        std::cout << queen_in_row[i];
        for (j = 0; j < board_size; ++j) {
            if (j == queen_in_row[i]) {
                std::cout << "Q";
            } else {
                std::cout << " .";
            }
        }
        std::cout << std::endl;
    }
}

bool Queens::unguarded(int col) const {
    return col_free[col]
           && upward_free[col + col]
           && downward_free[count - col + board_size - 1];

}

void Queens::insert(int col) {
    queen_in_row[count] = col;
    col_free[col] = false;
    upward_free[count + col] = false;
    downward_free[count - col + board_size - 1] = false;
}

void Queens::remove(int col) {
    queen_in_row[count] = col;
    col_free[col] = true;
    upward_free[count + col] = true;
    downward_free[count - col + board_size - 1] = true;
}


void run_queen() {

}

#endif //UNGEE_DATASTRUCTURES_EIGHT_QUEENS_H
