//
// Created by hsun on 11/15/2017.
//

#ifndef DATASTRUCTURES_MINHEAP_H
#define DATASTRUCTURES_MINHEAP_H

#include <vector>
#include <map>
#include <iostream>

using namespace std;

template <class T>
class MinHeap {
private:
    vector<int> keys;
    vector<T> values;
    void bubble_down(const int& i); // O(log n)
    void bubble_up(const int& i); // O(log n)
    void heapify(); // O(n log n)

public:
    MinHeap<T>();
    MinHeap<T>(const vector<int>& keys, const vector<T>& values);
    MinHeap<T>(const map<int, T>& pairs);
    void insert(const int& key, const T& value); // O(log n)
    T getMin(); // O(1)
    void removeMin(); // O(log n)

    template<class Y>
    friend ostream& operator<<(ostream& out, const MinHeap<Y>& minHeap);
};

#include "minHeap.cpp"
#endif //DATASTRUCTURES_MINHEAP_H
