//
// Created by hsun on 11/16/2017.
//

#ifndef DATASTRUCTURES_SORTTEST_H
#define DATASTRUCTURES_SORTTEST_H

#include <vector>
#include <iostream>
#include "../sort/sort.h"
#include "../sort/sort_int.h"

using namespace std;
void quick_sort_test() {
    vector<int> a = {65,72,4,10,94,5,2,1,6,7,1,4,2,89,21,12,54,17,97};
    Sort<int>::quick1(a);
    for (int i =0;i<a.size();i++) cout << a[i] << ", ";
}


void radix_sort_test() {
    vector<int> a = {-65,-72,4,10,94,5,2,-1,-6,7,1,4,-2,89,21,12,54,17,97};
    SortInt::radix(a, 10);
    for (int i =0;i<a.size();i++) cout << a[i] << ", ";
}

void count_sort_test() {
    vector<int> a = {1, 4, 1, 2, 8, 5, 2};
    SortInt::count(a);
    for (int i =0;i<a.size();i++) cout << a[i] << ", ";

}

void count_radix_sort_test() {
    vector<int> a = {-65,-72,4,10,94,5,2,-1,-6,7,1,4,-2,89,21,12,54,17,97};
    SortInt::radix(a, 10);
    for (int i =0;i<a.size();i++) cout << a[i] << ", ";
}
#endif //DATASTRUCTURES_SORTTEST_H
