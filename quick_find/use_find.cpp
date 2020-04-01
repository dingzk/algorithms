//
// Created by zhenkai on 2020/4/1.
//

#include "find.h"
#include <iterator>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
//    ostream_iterator<int, char> out(cout, " ");

    vector<int> a = {0, 2, 4, 1, 9, 8};
    Find f(a);
//    int  j = f.find_k(0, 5, 9);
    int  j = f.find_k_min(0, 5, 5);
    cout << j << endl;

    return 0;

}