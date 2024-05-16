#include "bits/stdc++.h"
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    set<char> v;
    v.insert('a');
    v.insert('e');
    v.insert('i');
    v.insert('o');
    v.insert('u');
    v.insert('y');
    int n = 0;
    while (cin >> n) {
        if (n == 0) {
            return 0;
        }
        string name;
        long long maxV = 0;
        long long maxOne = 0;
        for (int i = 0; i < n; i++) {
            maxOne = 0;
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); j++) {
                if (j < s.size() - 1 && v.find(s[j]) != v.end() && v.find(s[j + 1]) != v.end() && s[j] == s[j + 1]) {
                    maxOne++;
                }
            }
            if (maxOne >= maxV) {
                maxV = maxOne;
                name = s;
            }
        }
        cout << name << endl;
    }
}