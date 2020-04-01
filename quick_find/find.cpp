//
// Created by zhenkai on 2020/4/1.
//

#include "find.h"
#include <vector>

using std::vector;

Find::Find(vector<int> &arr)
{
    find_arr = arr;
}

// O(n)
int Find::partition(int i, int j)
{
    int p = i;
    int temp;

    while ( i < j) {
        if (find_arr[i] < find_arr[j]) {
            // swap
            temp = find_arr[i];
            find_arr[i] = find_arr[p];
            find_arr[p] = temp;
            p += 1;
        }
        i++;
    }
    if (p != j) {
        temp = find_arr[p];
        find_arr[p] = find_arr[j];
        find_arr[j] = temp;
    }

    return p;
}

//O(n)
int Find::find_k_min(int i, int j, int k)
{
    int p;
    if (k > j || k < i) {
        return -1;
    }
    p = partition(i, j);
    if (k == p) {
        return find_arr[p];
    }
    if ( k > p) {
        return find_k_min(p + 1, j, k);
    } else {
        return find_k_min(i, p - 1, k);
    }

}

//O(n)
int Find::find_k(int i, int j, int key)
{
    int p;
    p = partition(i, j);
    if (key == find_arr[p]) {
        return p;
    }
    if (i == j) {
        return -1;
    }
    if ( key > find_arr[p]) {
        return find_k(p + 1, j, key);
    } else {
        return find_k(i, p - 1, key);
    }

}