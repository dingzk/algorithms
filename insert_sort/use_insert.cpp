//
// Created by zhenkai on 2020/4/21.
//

#include "insertion.h"
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>

std::ostream_iterator<int, char> out(std::cout, " ");

int main(void)
{
    std::vector<int> a = {6,7,1,3,8,11};

    Insertion ins(a);

    ins.sort();

    copy(ins.get_sort().begin(), ins.get_sort().end(), out);

    return 0;
}