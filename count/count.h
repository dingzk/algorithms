//
// Created by zhenkai on 2020/3/22.
// 计数排序
//

#ifndef ALGORITHMS_COUNT_H
#define ALGORITHMS_COUNT_H

#include <vector>

#define MAX_V 10

using namespace std;

class Count
{
private:
    vector<int> sort_arr;
public:
    Count(vector<int> &a) : sort_arr(a) {}
    void sort_1();
    void sort_2();
    vector<int> & get_sort_arr() {
        return sort_arr;
    }
    virtual ~Count(){}

};


#endif //ALGORITHMS_COUNT_H
