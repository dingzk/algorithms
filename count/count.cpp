//
// Created by zhenkai on 2020/3/22.
// 计数排序
//

#include "count.h"
#include <iostream>

//O(MAX_V+n)
void Count::sort_1()
{
    int *temp = new int[MAX_V + 1]();
    vector<int> sort_temp(sort_arr);
    // 为每个数计数
    vector<int>::iterator iter;
    for (iter = sort_temp.begin() ;iter != sort_temp.end(); iter ++) {
        if (*iter > MAX_V) {
            std::cout << "out of max_v";
            return;
        }
        temp[*iter] ++;
    }
    // 累加计数
    for (int i = 1; i <= MAX_V; i++ ) {
        temp[i] = temp[i] + temp[i - 1];
    }
    // 排序
    vector<int>::reverse_iterator riter;
    for (riter = sort_temp.rbegin() ;riter != sort_temp.rend(); riter ++) {
        sort_arr[temp[*riter] - 1] = *riter; //  索引从0开始的
        temp[*riter] --;
    }
    delete []temp;

    return;
}
