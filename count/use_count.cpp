//
// Created by zhenkai on 2020/3/22.
//

#include "count.h"
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    ostream_iterator<int, char> out (cout, " ");

    vector<int> a = {2,5,3,0,2,3,0,0,1,2,3,3};

    Count sort_obj(a);

    sort_obj.sort_2();

    copy(sort_obj.get_sort_arr().begin(), sort_obj.get_sort_arr().end(), out);

    return 0;

}

