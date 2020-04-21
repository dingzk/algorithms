//
// Created by zhenkai on 2020/4/21.
//

#ifndef ALGORITHMS_INSERTION_H
#define ALGORITHMS_INSERTION_H

#include <iostream>
#include <vector>
#include <iterator>

class Insertion
{
private:
    std::vector<int> sort_arr;
public:
    Insertion(std::vector<int> & arr);
    void sort();

    std::vector<int> & get_sort() {
        return sort_arr;
    }

};


#endif //ALGORITHMS_INSERTION_H
