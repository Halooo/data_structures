//
// Created by hsun on 11/30/2017.
//

#ifndef DATASTRUCTURES_SORT_INT_H
#define DATASTRUCTURES_SORT_INT_H
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class SortInt {
private:
    static void radix_sort(vector<int> &arr, const int base);
public:
    static void radix(vector<int> &arr, const int base);
};

#endif //DATASTRUCTURES_SORT_INT_H
