//
// Created by zhenkai on 2020/3/15.
//

#include "merge.h"
#include <limits.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> Merge::merge_inner(vector<int> &sort_a, vector<int> &sort_b)
{
    int m, n = 0;
    int x = sort_a.size();
    int y = sort_b.size();
    vector<int> sort_c;

    sort_a.push_back(INT_MAX);
    sort_b.push_back(INT_MAX);

    for (int i = 0; i < x + y; i++) {
        if (sort_a[m] > sort_b[n]) {
            sort_c.push_back(sort_b[n]);
            n ++;
        } else {
            sort_c.push_back(sort_a[m]);
            m ++;
        }
    }

    return sort_c;
}

//O(n)
void Merge::merge(int p, int q, int r)
{
    if (q < p || q > r) {
        return;
    }
    vector<int> sort_a(sort_arr.begin() + p, sort_arr.begin() + q + 1);
    vector<int> sort_b(sort_arr.begin() + q + 1,  sort_arr.begin() + r + 1);

    sort_a.push_back(INT_MAX); //哨兵元素
    sort_b.push_back(INT_MAX); // 哨兵元素

    int m = 0, n = 0;
    for (int i = p; i <= r; i++) {
        if (sort_a[m] > sort_b[n]) {
            sort_arr[i] = sort_b[n];
            n ++;
        } else {
            sort_arr[i] = sort_a[m];
            m ++;
        }
    }

    return;
}

//O(nlgn)
void Merge::sort(int p, int r)
{
    if (p < r) {
        int q = (r + p) / 2;
        sort(p, q); // left
        sort(q + 1, r); // right
        merge(p, q, r);
    }
}
