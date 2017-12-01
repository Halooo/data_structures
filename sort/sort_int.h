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
    static void radix_sort(vector<int> &arr, int base);
    static void radix_count_subroutine(vector<int> &arr, int base, int exp);
    static void count_radix_sort(vector<int> &arr, int base);
public:
    static void radix(vector<int> &arr, int base); // O(kn), where k is digit number of largest number
    static void count_radix(vector<int> &arr, int base);
    static void count(vector<int> &arr); // O(n + R), where R is the largest number in arr
};

#endif //DATASTRUCTURES_SORT_INT_H
