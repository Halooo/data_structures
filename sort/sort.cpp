//
// Created by hsun on 11/24/2017.
//

#include <queue>
#include <algorithm>
#include "sort.h"

//using namespace std;
//
//template <class T>
//void Sort<T>::radix(vector<int> &arr, const int base) {
//    queue<int> bucket[base];
//    vector<int> output[arr.size()];
//    auto max = *max_element(arr.begin(), arr.end());
//    for (int power = 1; max != 0; max /= base, power *= base) {
//        for (auto i = output->begin(); i != output->end(); i++) {
//            int bucketNum = (*i / power % base);
//            bucket[bucketNum].push(*i);
//        }
//        auto it = output->begin();
//        for (int i = 0; i < base; i++) {
//            int bucketSize = bucket[i].size();
//            for (int j = 0; j < bucketSize; j++, it++) {
//                *it = bucket[i].front();
//                bucket[i].pop();
//            }
//        }
//    }
//}