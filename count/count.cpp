//
// Created by zhenkai on 2020/3/22.
// 计数排序
//

#include "count.h"
#include <iostream>

//O(MAX_V+n)
// 稳定版排序，非原址排序
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
    // 稳定排序
    vector<int>::reverse_iterator riter;
    for (riter = sort_temp.rbegin() ;riter != sort_temp.rend(); riter ++) {
        sort_arr[temp[*riter] - 1] = *riter; //  索引从0开始的
        temp[*riter] --;
    }
    delete []temp;

    return;
}

//O(MAX_V+n)
// 非稳定版排序，原址排序
void Count::sort_2()
{
    int *temp = new int[MAX_V + 1]();
    vector<int>::iterator iter;
    for (iter = sort_arr.begin(); iter != sort_arr.end(); iter ++) {
        if (*iter > MAX_V) {
            std::cout << "out of max_v";
            return;
        }
        temp[*iter] ++;
        *iter = 0; // init to 0
    }
    int j = 0;
    for (j = 1; j <= MAX_V; j++) {
        temp[j] = temp[j] + temp[j - 1];
    }
    // 逆向通过temp把sort_arr再解开
//    for (int k = MAX_V ; k > 1; k--) {
//        while (temp[k] > temp[k - 1]) {
//            sort_arr[temp[k] - 1] = k;
//            temp[k] -- ;
//        }
//    }

    // 正向通过temp把sort_arr再解开
    for (int k = 0 ; k <= MAX_V; k++) {
        int tempk = temp[k];
        int prev = k == 0 ? 0 : temp[k-1];
        while (tempk-- > prev) {
            sort_arr[tempk] = k;
        }
    }

    return;
}