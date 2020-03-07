//
// Created by zhenkai on 2020/3/7.
//

#include "heap.h"
#include <iterator>

// O(lgn = O(h))
void Heap::max_heapify(int index, int max_index)
{
    int l = left(index);
    int r = right(index);
    int temp, largest;
    if (l <= max_index && a[l] > a[index]) {
        largest = l;
    } else {
        largest = index;
    }
    if (r <= max_index && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != index) {
        temp = a[index];
        a[index] = a[largest];
        a[largest] = temp;
        return max_heapify(largest, max_index);
    }
}

// O(n) < O < O(nlgn)
void Heap::build_max_heap()
{
    int len = a.size();
    int now_index = (len >> 1) - 1;

    while (now_index >= 0) {
        max_heapify(now_index, len - 1);
        now_index--;
    }

}

// O(nlgn)
void Heap::sort_heap()
{
    int max_index = a.size() - 1;
    build_max_heap();
    int temp;
    while (max_index >= 1) {
        // exchange a[0] to a[n]
        temp = a[max_index];
        a[max_index] = a[0];
        a[0] = temp;
        // rebuild A(0)
        max_heapify(0, max_index - 1);
        max_index -- ;
    }

}

int Heap::maximum()
{
    return a[0];
}

int Heap::extract_max()
{
    int len = a.size();
    int max = a[0];
    a[0] = a[len - 1];
    a.pop_back();

    max_heapify(0, len -2);

    return max;
}

void Heap::increase_key(int index, int key)
{
    if (a[index] > key) {
        cout << "insert value is smaller than old" << endl;
        exit(1);
    }
    a[index] = key;
    int max_index = a.size() - 1;
    int now_index = index;
    int temp;

    while (now_index > 0 && a[parent(now_index)] < a[now_index]) {
        // exchange
        temp = a[now_index];
        a[now_index] = a[parent(now_index)];
        a[parent(now_index)] = temp;

        now_index = parent(now_index);
    }

}

void Heap::insert(int key)
{
    a.push_back(key);
    increase_key(a.size() - 1, key);

}
