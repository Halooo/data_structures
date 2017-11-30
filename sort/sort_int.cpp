//
// Created by hsun on 11/30/2017.
//
#include "sort_int.h"
#include <algorithm>

void SortInt::radix_sort(vector<int> &arr, const int base) {
    queue<int> bucket[base];
    auto max = *max_element(arr.begin(), arr.end());
    int max_digit = 0, tmp_max = max, curr_digit = 0;
    while(tmp_max != 0) {
        ++max_digit;
        tmp_max /= base;
    }
    while(curr_digit < max_digit) {
        for(unsigned i = 0; i < arr.size(); i++) {
            int div = pow(base, curr_digit);
            int num = arr[i];
            int digit_val = (num / div) % base;
            bucket[digit_val].push(num);
        }
        int i = 0;
        for(int j = 0; j < base; j++) {
            while(!bucket[j].empty()) {
                int temp = bucket[j].front();
                arr[i] = temp;
                bucket[j].pop();
                ++i;
            }
        }
        ++curr_digit;
    }
}

void SortInt::radix(vector<int> &arr, const int base) {
    vector<int> positive;
    vector<int> negative;
    for (auto i : arr) {
        if (i < 0) {
            negative.emplace_back(-i);
        } else {
            positive.emplace_back(i);
        }
    }
    radix_sort(positive, base);
    radix_sort(negative, base);
    vector<int> tmp;
    for(int i = 0; i < negative.size(); i++) tmp.emplace_back(i);
    transform(negative.begin(), negative.end(), tmp.begin(), [](int x) {return -x;});
    reverse(tmp.begin(), tmp.end());
    tmp.insert(tmp.end(), positive.begin(), positive.end());
    arr = tmp;
}