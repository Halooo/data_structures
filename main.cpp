#include <iostream>
#include "minHeap.h"
using namespace std;

void min_heap_test() {
    auto hp = new MinHeap();
    hp->insert(9);
    hp->insert(3);
    hp->insert(5);
    hp->insert(1);
    hp->insert(6);
    hp->insert(14);
    hp->insert(5);
    hp->insert(1);
    hp->insert(3);
    cout << *hp << endl;
}

int main() {
    min_heap_test();
    return 0;
}


