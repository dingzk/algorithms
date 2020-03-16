//
// Created by zhenkai on 2020/3/15.
//

#include "quick.h"
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> sort_a = {2, 3, 8, 7, 1, 3, 5, 6, 4, 5};

    Quick qobj(sort_a);

    qobj.merge_sort(0, sort_a.size() - 1);

    ostream_iterator<int, char> out(cout, " ");

    copy(qobj.get_sort_arr().begin(), qobj.get_sort_arr().end(), out);

    return 0;

}