//
// Created by zhenkai on 2020/3/15.
//

#ifndef ALGORITHMS_QUICK_H
#define ALGORITHMS_QUICK_H

#include <vector>
using namespace std;

class Quick
{
private:
    vector<int> sort_arr;
public:
    Quick(vector<int> & a) : sort_arr(a) {}
    virtual ~Quick(){}
    int quick_sort1(int i, int j);
    int quick_sort2(int i, int j);
    void merge_sort(int i, int j);

    vector<int> & get_sort_arr() {
        return sort_arr;
    }
};


#endif //ALGORITHMS_QUICK_H
