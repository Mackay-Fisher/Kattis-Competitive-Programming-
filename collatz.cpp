#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(){
    long long v1,v2;
    while (true)
    {
        cin >> v1 >> v2;
        if(v1==0 && v2 ==0){
            break;
        }
    unordered_map<long long, int> path1, path2;
    unordered_set<long long> set1, set2;

    long long cur1 = v1, cur2 = v2;
    int steps1 = 0, steps2 = 0;

    set1.insert(v1);
    set2.insert(v2);
    path1[v1] = steps1;
    path2[v2] = steps2;
    long long intersection_val = -1;

    while (true) {
        if (set2.find(cur1) != set2.end()) {
            intersection_val = cur1;
            break;
        }
        if (cur1 != 1) {
            cur1 = (cur1 % 2 ==0) ? cur1/2 : 3 * cur1 + 1;
            set1.insert(cur1);
            path1[cur1] = ++steps1;
        }
        if (set1.find(cur2) != set1.end()) {
            intersection_val = cur2;
            break;
        }
        if (cur2 != 1) {
            cur2 = (cur2 % 2 ==0) ? cur2/2 : 3 * cur2 + 1;
            set2.insert(cur2);
            path2[cur2] = ++steps2;
        }
    }
    long long stepsP1 = path1[intersection_val];
    long long stepsP2 = path2[intersection_val];
    cout << v1 << " needs " << stepsP1 << " steps, " << v2 << " needs " << stepsP2 << " steps, they meet at " << intersection_val << "\n";
    }
}