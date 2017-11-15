
/*
 * left child of A[i] is A[2i+1]
 * Right child of A[i] is A[2i+2]
 * Parent of A[i] is A[floor((i-1)/2)]
 */

#include "minHeap.h"
#include <iostream>
#include <algorithm>

using namespace std;

MinHeap::MinHeap() {}

void MinHeap::bubble_up(int i) {
    int curr = i;
    int curr_parent = (curr - 1) / 2;
    while(keys[curr_parent] > keys[curr]) {
//        cout << "swapping: " << keys[curr] << " <-> " << keys[curr_parent] << endl;
        iter_swap(keys.begin() + curr, keys.begin() + curr_parent);
        curr = curr_parent;
        curr_parent = (curr - 1) / 2;
    }
}

void MinHeap::insert(int key) {
    int len = keys.size();
    keys.emplace_back(key);
    bubble_up(len);
}

ostream& operator<<(ostream& out, const MinHeap& heap)
{
    for (int i = 0; i < heap.keys.size(); i++) {
        out << i << " : " << heap.keys[i] << endl;
    }

    return out;
}