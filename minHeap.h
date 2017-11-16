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
    void bubble_down(const int& i);
    void bubble_up(const int& i);
    void heapify();

public:
    MinHeap<T>();
    MinHeap<T>(const vector<int>& keys, const vector<T>& values);
    MinHeap<T>(const map<int, T>& pairs);
    void insert(const int& key, const T& value);
    T getMin();
    void removeMin();

    template<class Y>
    friend ostream& operator<<(ostream& out, const MinHeap<Y>& minHeap);
};

#include "minHeap.cpp"
#endif //DATASTRUCTURES_MINHEAP_H
