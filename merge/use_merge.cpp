//
// Created by zhenkai on 2020/3/15.
//

#include "merge.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


int main(void)
{
    vector<int> a = {5, 2, 4, 7, 1, 3, 2, 6, 8};

    vector<int> b = {2,4,5,7,8, 1,2,3,6};

    Merge sortobj(a);
    sortobj.sort(0, a.size() - 1);
//    sortobj.merge(0, 4, 8);

    ostream_iterator<int, char> out(cout, " ");

    copy(sortobj.get_sortarr().begin(), sortobj.get_sortarr().end(), out);
//    copy(a.begin(), a.end(), out);
    cout << endl;

    return 0;

}