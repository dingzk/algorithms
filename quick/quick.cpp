//
// Created by zhenkai on 2020/3/15.
//

#include "quick.h"
#include <vector>
#include <iostream>
using namespace std;

// i 指向第一个比key大的数，j指向第一个比key小的数，然后右侧交换到左侧
int Quick::quick_sort1(int i, int j)
{
    int m = i - 1;
    int n = i;
    int key = sort_arr[j];
    int tmp;
    while(n < j) {
        if (sort_arr[n] < key) {
            m ++;
            if (m < n) {
                // swap
                tmp = sort_arr[n];
                sort_arr[n] = sort_arr[m];
                sort_arr[m] = tmp;
            }
        }
        n++;
    }

    // swap
    sort_arr[j] = sort_arr[m + 1];
    sort_arr[m + 1] = key;

    return m + 1;
}

// 先自增或自减解决临界问题
int Quick::quick_sort2(int i, int j)
{
    int m = i - 1;
    int n = j;
    int key = sort_arr[j];
    int temp;
    while (true)
    {
        while (true)
        {
            m++;
            if (sort_arr[m] >= key)
            {
                break;
            }
        }
        while (true)
        {
            n--;
            if (sort_arr[n] <= key)
            {
                break;
            }
        }

        // switch
        if (m < n)
        {
            temp = sort_arr[n];
            sort_arr[n] = sort_arr[m];
            sort_arr[m] = temp;
        } else {
            break;
        }
    }

    temp = sort_arr[j];
    sort_arr[j] = sort_arr[m];
    sort_arr[m] = temp;

    return m;

}

//O(nlgn)
void Quick::merge_sort(int i, int j)
{
    int k;
    if (i < j) {
        k = quick_sort1(i, j);
        merge_sort(i, k - 1);
        merge_sort(k + 1, j);
    }
}