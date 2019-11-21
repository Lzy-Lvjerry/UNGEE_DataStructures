//
// Created by lvjer on 2019/11/20.
//

#include "Sort.h"
#include <iostream>

void Sort::quick_sort(int *nums, int left, int right) {
    int pivot = nums[left];
    int row = left, high = right;
    while (left < right) {
        while (left < right && pivot <= nums[right]) {
            right--;
        }
        nums[left] = nums[right];
        while (left < right && pivot >= nums[left]) {
            left++;
        }
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    if (row < high) {
        quick_sort(nums, row, left - 1);
        quick_sort(nums, left + 1, high);
    }
}

void Sort::print_all(const int *nums, const int left, const int right) {
    for (int i = left; i <= right; ++i) {
        std::cout << "Nums: " << nums[i] << "  ";
    }
    std::cout << std::endl;
}
