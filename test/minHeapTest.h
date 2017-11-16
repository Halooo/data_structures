//
// Created by hsun on 11/16/2017.
//
#include "../minHeap.h"
#include <map>
#include <vector>

void min_heap_test() {
    map<int, char> m = {{9, 'f'}, {23, '!'}, {3, 'c'}, {14, 'o'}, {5, 'e'}, {6, ' '}, {22, 'g'}, {11, 'r'}, {1, 'i'}};
    vector<int> v1 = {9,3,5,1,6,5,14,3,1};
    vector<char> v2 = {'a','o','l','h','o',' ','H','l','e'};
    auto hp = new MinHeap<int>();
    auto hp1 = new MinHeap<char>(v1, v2);
    auto hp2 = new MinHeap<char>(m);
    hp->insert(9,9);
    hp->insert(3,3);
    hp->insert(5,5);
    hp->insert(1,1);
    hp->insert(6,6);
    hp->insert(14,14);
    hp->insert(5,5);
    hp->insert(1,1);
    hp->insert(3,3);
    cout << *hp << endl;
    cout << *hp1 << endl;
    cout << *hp2 << endl;

}