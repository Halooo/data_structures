//
// Created by hsun on 11/16/2017.
//

#ifndef DATASTRUCTURES_SORT_H
#define DATASTRUCTURES_SORT_H

#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T>
class Sort {
private:
    static int choose_pivot1(const int& a, const int& b);
    static void partition_quick(vector<T> &arr, int low, int high);
    static void quick_helper(vector<T> &arr, int low, int high);
public:
    static void quick1(vector<T> &arr);
};


template <class T>
int Sort<T>::choose_pivot1(const int& a, const int& b) {
    return rand()%(b - a) + a;
}

template <class T>
void Sort<T>::partition_quick(vector<T> &arr, int low, int high) {
    int i = low, j = high;
//    int pivot = choose_pivot1(low, high);
    int pivot = (low+high)/2;
    while (i < j) {
        while (arr[i] < arr[pivot]) {
            i++;
        }
        while (arr[j] > arr[pivot]) {
            j--;
        }
        if (i <= j) {
            iter_swap(arr.begin() + i, arr.begin() + j);
            i++;
            j--;
        }
    }
    if (low < j) {
        partition_quick(arr, low, j);
    }
    if (i < high) {
        partition_quick(arr, i, high);
    }
}


template <class T>
void Sort<T>::quick1(vector<T> &arr) {
    partition_quick(arr, 0, arr.size() - 1);
}



#endif //DATASTRUCTURES_SORT_H
