#include "bits/stdc++.h"
#include <string>
#include <map>
using namespace std;

struct NewSort 
{
    bool operator() (const pair<string,long long>& p1, const pair<string,long long>& p2) {
        if (p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }
};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector< pair<string,long long> > output;
        map<string, long long> map;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            string s;
            int num;
            cin >> s >> num;
            map[s] += num;
        }
        for (auto p: map) {
            output.push_back(p);
        }
        sort(output.begin(), output.end(), NewSort());
        cout << map.size() << endl;
        for (int i = 0; i < output.size(); i++) {
            cout << output[i].first << " " << output[i].second << endl;
        }
    }
}