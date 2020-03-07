//
// Created by zhenkai on 2020/3/7.
//


#include "heap.h"
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ostream_iterator<int, char> out(cout, " ");
//    vector<int> a = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7}; //c++11

    vector<int> a = {5, 13, 2, 25, 7, 17, 20, 8, 4};

    Heap heap(a);

    // build max_heap
    heap.build_max_heap();

    copy(heap.get_arr().begin(), heap.get_arr().end(), out);

    cout << "\n";

    // sort
    heap.sort_heap();

    copy(heap.get_arr().begin(), heap.get_arr().end(), out);

    cout << "\n";

    return 0;
}