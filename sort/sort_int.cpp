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
        for(auto &i : arr) {
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
    for (auto &i : arr) {
        if (i < 0) {
            negative.emplace_back(-i);
        } else {
            positive.emplace_back(i);
        }
    }
    radix_sort(positive, base);
    radix_sort(negative, base);
    vector<int> tmp(negative.size());
    transform(negative.begin(), negative.end(), tmp.begin(), [](int x) {return -x;});
    reverse(tmp.begin(), tmp.end());
    tmp.insert(tmp.end(), positive.begin(), positive.end());
    arr = tmp;
}

void SortInt::count(vector<int> &arr) {
    auto max = *max_element(arr.begin(), arr.end());
    vector<int> counting(max + 1);
    vector<int> result(arr.size());
    for (auto &i : arr) {
        ++counting[i];
    }

    for (int i = 1 ; i < counting.size(); ++i) {
        counting[i] += counting[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        --counting[arr[i]];
        result[counting[arr[i]]] = arr[i];
    }
    arr = result;
}

void SortInt::radix_count_subroutine(vector<int> &arr, const int base, const int exp) {
    vector<int> counting(base + 1);
    vector<int> result(arr.size());
    for (auto &i : arr) {
        ++counting[(arr[i] / exp) % base];
    }

    for (int i = 1 ; i < counting.size(); ++i) {
        counting[i] += counting[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        --counting[arr[(arr[i] / exp) % base]];
        result[counting[arr[(arr[i] / exp) % base]]] = arr[i];
    }
    arr = result;
}

void SortInt::count_radix_sort(vector<int> &arr, const int base) {
    auto max = *max_element(arr.begin(), arr.end());

    for (int exp = 1; max / exp > 0; exp *= base) {
        radix_count_subroutine(arr, base, exp);
    }
}

void SortInt::count_radix(vector<int> &arr, const int base) {
    vector<int> positive;
    vector<int> negative;
    for (auto &i : arr) {
        if (i < 0) {
            negative.emplace_back(-i);
        } else {
            positive.emplace_back(i);
        }
    }
    count_radix_sort(positive, base);
    count_radix_sort(negative, base);
    vector<int> tmp(negative.size());
    transform(negative.begin(), negative.end(), tmp.begin(), [](int x) {return -x;});
    reverse(tmp.begin(), tmp.end());
    tmp.insert(tmp.end(), positive.begin(), positive.end());
    arr = tmp;
}