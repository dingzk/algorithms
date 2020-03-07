//
// Created by zhenkai on 2020/3/7.
//

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// 索引从0开始
#define PARENT(i) (((i +1) >> 1) - 1)
#define LEFT(i) (((i +1) << 1) - 1)
#define RIGHT(i) ((i + 1) << 1)

// O(lgn)
void max_heapify(vector<int> &a, int i, int max_index)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest;
    int temp;
    cout << l << " " << r  << " --- "<< endl;

    if (l <= max_index && a[i] < a[l]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r <= max_index && a[largest] < a[r]) {
        largest = r;
    }
    if (i != largest) {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        return max_heapify(a, largest, max_index);
    }
}

//  从非叶子节点开始build最大堆
void build_max_heap(vector<int> &a)
{
    int len = (a.size() >> 1) - 1;
    while (len >= 0) {
        cout << "len: " << len << endl;
        max_heapify(a, len, a.size() - 1);
        len --;
    }
}

// 循环使用最大堆进行排序 堆顶的是最大值
// O(nlgn)
void sort_heap(vector<int> &a)
{
    int len = a.size() - 1;
    build_max_heap(a);
    int max_tmp;
    while (--len >= 0) {
        // exchange a[0] a[n]
        max_tmp = a[len + 1];
        a[len + 1] = a[0];
        a[0] = max_tmp;
        // rebuild A(0)
        max_heapify(a, 0, len);
    }
}

int main(void)
{
    ostream_iterator<int, char> out(cout, " ");
//    vector<int> a = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7}; //c++11

    vector<int> a = {5, 13, 2, 25, 7, 17, 20, 8, 4};

    // build max_heap
    build_max_heap(a);

    copy(a.begin(), a.end(), out);

    // sort
    sort_heap(a);

    copy(a.begin(), a.end(), out);

    return 0;
}