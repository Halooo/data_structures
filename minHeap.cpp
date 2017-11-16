
/*
 * left child of A[i] is A[2i+1]
 * Right child of A[i] is A[2i+2]
 * Parent of A[i] is A[floor((i-1)/2)]
 */
#ifdef DATASTRUCTURES_MINHEAP_H

#include "minHeap.h"
#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
MinHeap<T>::MinHeap() {}

template <class T>
MinHeap<T>::MinHeap(const vector<int>& keys, const vector<T>& values):keys{keys}, values{values} {
    if (keys.size() != values.size()) {
        throw "error: make sure each key pairs with one value";
    }
    heapify();
}

template <class T>
MinHeap<T>::MinHeap(const map<int, T>& pairs) {
    for (auto it = pairs.begin(); it != pairs.end(); ++it) {
      int key = it->first;
      T value = it->second;
      keys.emplace_back(key);
      values.emplace_back(value);
    }
    heapify();
}

// O(n log n)
template <class T>
void MinHeap<T>::heapify() {
    for (int i = keys.size() - 1; i >= 0; --i) {
        bubble_down(i);
    }
}

// O(1)
template <class T>
T MinHeap<T>::getMin() {
    return values[0];
}

// O(log n)
template <class T>
void MinHeap<T>::insert(const int& key, const T& value) {
    int len = keys.size();
    keys.emplace_back(key);
    values.emplace_back(value);
    bubble_up(len);
}

// O(log n)
template <class T>
void MinHeap<T>::bubble_up(const int &i) {
    int curr = i;
    int curr_parent = (curr - 1) / 2;
    while(keys[curr_parent] > keys[curr]) {
        iter_swap(keys.begin() + curr, keys.begin() + curr_parent);
        iter_swap(values.begin() + curr, values.begin() + curr_parent);
        curr = curr_parent;
        curr_parent = (curr - 1) / 2;
    }
}

// O(log n)
template <class T>
void MinHeap<T>::bubble_down(const int &i) {
    int curr = i;
    int min_i = curr;
    int len = keys.size();
    while (curr <= len) { // traverse until hits a leaf
        int curr_left = 2 * curr + 1;
        int curr_right = 2 * curr + 2;
        if ((curr_left < len) && (keys[curr] > keys[curr_left])) {
            min_i = curr_left;
        } else {
            min_i = curr;
        }
        if ((curr_right < len) && (keys[min_i] > keys[curr_right])) {
            min_i = curr_right;
        }
        if (min_i != curr) {
            iter_swap(keys.begin() + curr, keys.begin() + min_i);
            iter_swap(values.begin() + curr, values.begin() + min_i);
            curr = min_i;
        } else {
            break;
        }
    }
}

template <class T>
void MinHeap<T>::removeMin() {
    int len = keys.size();
    if (len == 0) {
        return;
    }
    keys[0] = keys[len - 1];
    values[0] = values[len - 1];
    keys.pop_back();
    values.pop_back();
    bubble_down(0);
}

template <class T>
ostream& operator<<(ostream& out, const MinHeap<T>& minHeap) {
    for (int i = 0; i < minHeap.keys.size(); i++) {
        try {
            out << minHeap.keys[i] << " : " << minHeap.values[i] << endl;
        } catch (string e) {
            cerr << e << endl;
        }
    }
    return out;
};

#endif