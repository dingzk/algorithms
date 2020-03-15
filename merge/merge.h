//
// Created by zhenkai on 2020/3/15.
// 归并排序
//

#ifndef ALGORITHMS_MERGE_H
#define ALGORITHMS_MERGE_H

#include <vector>
using namespace std;

class Merge
{
private:
    vector<int> sort_arr;
public:
    Merge(vector<int> & arr) : sort_arr(arr) {}

    vector<int> merge_inner(vector<int> & sort_a, vector<int> & sort_b);
    void merge(int p, int q, int r);
    void sort(int p, int r);
    vector<int> & get_sortarr() {
        return sort_arr;
    }

    virtual ~Merge(){}
};


#endif //ALGORITHMS_MERGE_H
