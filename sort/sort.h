//
// Created by hsun on 11/16/2017.
//

#ifndef DATASTRUCTURES_SORT_H
#define DATASTRUCTURES_SORT_H

#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

template<class T>
class Sort {
private:
    static int choose_pivot1(const int& a, const int& b);
    static void partition_quick(vector<T> &arr, size_t left, size_t right);
public:
    static void quick1(vector<T> &arr);
};


template <class T>
int Sort<T>::choose_pivot1(const int& a, const int& b) {
    srand(time(NULL));
    return rand() % (b - a) + a;
}

template <class T>
void Sort<T>::partition_quick(vector<T> &arr, size_t left, size_t right) {
    size_t l = left;
    size_t r = right - 1;
    size_t size = right - left;

    if (size > 1) {
        T pivot = arr[rand() % size + l];
        while (l < r) {
            while (arr[r] > pivot && r > l) {
                r--;
            }
            while (arr[l] < pivot && l <= r) {
                l++;
            }
            if (l < r) {
                iter_swap(arr.begin() + l, arr.begin() + r);
                l++;
            }
        }

        partition_quick(arr, left, l);
        partition_quick(arr, r, right);
    }
}

template <class T>
void Sort<T>::quick1(vector<T> &arr) {
    partition_quick(arr, 0, arr.size());
}

#endif //DATASTRUCTURES_SORT_H
