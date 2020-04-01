//
// Created by zhenkai on 2020/4/1.
// 找到第k小的值
// 找到值为k的位置
//

#ifndef ALGORITHMS_FIND_H
#define ALGORITHMS_FIND_H

#include <vector>
using std::vector;

class Find
{
private:
    vector<int> find_arr;
    int partition(int i, int j);

public:
    Find(vector<int> &arr);
    int find_k_min(int i, int j, int k);
    int find_k(int i, int j, int k);

//    ~Find(){};

};


#endif //ALGORITHMS_FIND_H
