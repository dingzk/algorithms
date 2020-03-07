//
// Created by zhenkai on 2020/3/7.
//

#ifndef ALGORITHMS_HEAP_H
#define ALGORITHMS_HEAP_H

#include <iostream>
#include <vector>

using namespace std;


class Heap
{
private:
    vector<int> a;

public:
    Heap(vector<int> &arr) : a(arr) {}

    int parent(int i) {
        return ((i + 1) >> 1) - 1;
    }
    int left(int i) {
        return ((i + 1) << 1) - 1;
    }
    int right(int i) {
        return (i + 1) << 1;
    }

    // heap sort
    void max_heapify(int index, int max_index);
    void build_max_heap();
    void sort_heap();

    // priority queue
    int maximum();
    int extract_max();
    void increase_key(int index, int key);
    void insert(int key);

    vector<int> & get_arr() { return a; }


    virtual ~Heap() {};

};


#endif //ALGORITHMS_HEAP_H
