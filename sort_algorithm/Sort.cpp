//
// Created by lvjer on 2019/11/20.
//

#include "Sort.h"
#include <iostream>

void Sort::quick_sort(int *nums, int _left, int _right) {
    int pivot = nums[_left];
    int left = _left, right = _right;
    while (_left < _right) {
        while (_left < _right && pivot <= nums[_right]) {
            _right--;
        }
        nums[_left] = nums[_right];
        while (_left < _right && pivot >= nums[_left]) {
            _left++;
        }
        nums[_right] = nums[_left];
    }
    nums[_left] = pivot;
    if (left < right) {
        quick_sort(nums, left, _left - 1);
        quick_sort(nums, _left + 1, right);
    }
}

void Sort::print_all(const int *nums, const int left, const int right) {
    for (int i = left; i <= right; ++i) {
        std::cout << "Nums: " << nums[i] << "  ";
    }
    std::cout << std::endl;
}
