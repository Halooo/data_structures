#include<iostream>
#include<vector>

using namespace std;

// p is pattern to be matched
// F is the failure array
// Time O(p.size()) => O(m)
// Space O(p.size()) => O(m)
vector<int> buildF(string p) {
    vector<int> F(p.size());
    F[0] = 0;
    int i = 1, j = 0;
    while (i < p.size()) {
        if (p[i] == p[j]) {
            j = j+1;
            F[i] = j;
            i = i+1;
        } else {
            if (j == 0) {
                F[i] = 0;
                i = i+1;
            } else {
                j = F[j-1];
            }
        }
    }
    return F;
}

// KMP string matching pattern
// Time O(s.size() + p.size()) => O(n+m)
// Space O(p.size()) => O(m)
bool KMP(string s, string p) {
    std::vector<int> F = buildF(p);
    int i = 0, j = 0;
    while (i < s.size() && j < p.size()) {
        if (s[i] == p[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = F[j-1];
            } else {
                i++;
            }
        }
    }
    if (j == p.size()) return true;
    return false;
}

main() {
    string s = "abcxabcdabcdabcy";
    string p = "abcdabcy";
    string p2 = "abcdc";
    cout << KMP(s,p) << endl << KMP(s,p2) << endl << KMP(s,s) << endl;
    return 0;
}