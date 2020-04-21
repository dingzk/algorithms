//
// Created by zhenkai on 2020/4/21.
//

// 插入排序，从最后一个待排序的元素往前依次比较找到合适的位置插入

// 稳定排序
// 原址排序
// O(n2)

#include "insertion.h"

Insertion::Insertion(std::vector<int> &arr) : sort_arr(arr) {}

void Insertion::sort()
{
    int len = sort_arr.size();
    int i, j, t;
    for (i = 1; i < len; ++i) {
        j = i - 1;
        int value = sort_arr[i];
        for (t = j; t >= 0; t--) {
            if (sort_arr[t] > value) {
                // 往前挪一位
                sort_arr[t + 1] = sort_arr[t];
            } else {
                // 前面都已经排好序了
                break;
            }
        }
        sort_arr[t + 1] = value;
    }

}