#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;
class FenwickTree {
public:
    vector<long long> bitVec;
    long long n;

    FenwickTree(long long v) {
        n = v;
        bitVec.assign(n + 1, 0);
    }

    void update(long long idx, long long val) {
        while (idx <= n) {
            bitVec[idx] += val;
            idx += idx & (-idx);
        }
    }

    long long getSum(long long idx) {
        long long sum = 0;
        while (idx > 0) {
            sum += bitVec[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};

int main()
{
    long long n, g;
    cin >> n >> g;
    vector<long long> output;
    vector<long long> gems;
    unordered_map<long long, long long> GemMap;
    for (long long i = 0; i < 6; i++)
    {
        long long gem;
        cin >> gem;
        GemMap[i] = gem;
    }
    vector<FenwickTree> Trees;
    for (long long i = 0; i < 6; i++)
    {
        FenwickTree Tree(n);
        Trees.push_back(Tree);
    }
    vector<long long> ghold;
    string number;
    cin >> number;
    for (long long i = 0; i < number.size(); i++)
    {
        ghold.push_back(number[i] - '0');
    }
    vector<long long> arrayOrder(n);
    long long index = 0;
    for (long long i = 0; i < ghold.size(); i++)
    {
        if (ghold[i] != 0){
            arrayOrder[index] = ghold[i];
            index++;
        }
    }
    for (long long i = 0; i < arrayOrder.size(); i++)
    {
        Trees[arrayOrder[i]-1].update(i+1, 1);
    }
    
    for (long long i = 0; i < g; i++)
    {
        long long t;
        cin >> t;
        if (t == 1)
        {
            // 1 = replace value
            long long a, b;
            cin >> a >> b;
            Trees[arrayOrder[a-1] - 1].update(a, -1);
            Trees[b - 1].update(a, 1);
            arrayOrder[a-1] = b;
        }
        else if (t == 2)
        {
            // set new value in map
            long long a, b;
            cin >> a >> b;
            GemMap[a-1] = b;

        }
        else if (t == 3)
        {
            // query range
            long long a, b;
            cin >> a >> b;
            long long sum = 0;
            for (long long j = 0; j < 6; j++)
            {
                sum += GemMap[j]*(Trees[j].getSum(b) - Trees[j].getSum(a-1));
            }
            output.push_back(sum);
        }
    }
    for (auto a : output)
    {
        cout << a << endl;
    }
}