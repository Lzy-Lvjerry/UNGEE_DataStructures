//
// Created by lvjer on 2019/11/20.
//

#include <iostream>
#include "sort_test.h"
#include "../sort_algorithm/Sort.h"

void quick_sort_test() {
    int nums[15] = {1, 34, 1, 2, 5, 213, 5, 45, 23, 34, 3, 243, 55, 43, 23};
    Sort::quick_sort(nums, 0, 14);
    std::cout << "Sorted nums:";
    for (int num : nums) {
        std::cout << num << " ";
    }
}