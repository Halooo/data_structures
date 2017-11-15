//
// Created by hsun on 11/15/2017.
//

#ifndef DATASTRUCTURES_MINHEAP_H
#define DATASTRUCTURES_MINHEAP_H

#include <vector>
#include <iostream>

using namespace std;

class MinHeap {
private:
    vector<int> keys;
//    void bubble_down(int i);
    void bubble_up(int i);
//    void heapify();

public:
    MinHeap();
    void insert(int key);
//    int getMin();
//    void removeMin();

    friend ostream& operator<<(ostream& out, const MinHeap& minHeap);
};
#endif //DATASTRUCTURES_MINHEAP_H
