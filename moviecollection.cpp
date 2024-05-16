#include <iostream>
#include <vector>
using namespace std;
/*This is based off of the geeks for geeks fenwick tree and then also youtube :(*/

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


int main() {
   long long n;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        long long r,m;
        cin >> m >> r;
        FenwickTree ft(m+r);
        vector<long long> movies(m);
        for (long long j = 0; j < m; j++)
        {
            movies[j] = r+j+1;
            ft.update(movies[j],1);
        }
        // for(auto &x:movies){
        //     cout << x << " ";
        // }
        long long top = r;
        for (int j = 0; j < r; j++)
        {
            long long x;
            cin >> x;
            long long pos = movies[x-1];
            cout << ft.getSum(pos) - 1 << " ";
            ft.update(movies[x-1],-1);
            movies[x-1] = top--;
            ft.update(movies[x-1],1);
        }
        cout<<endl;
    }
}