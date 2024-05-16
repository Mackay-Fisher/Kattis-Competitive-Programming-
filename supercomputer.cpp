#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include<set>
using namespace std;

class SegmentTree
{
private:
    vector<long long> array;
    vector<long long> segT;
    long long n;
    unordered_map<long long, long long> GM;

    long long MidVal(long long x, long long y) { return x + (y - x) / 2; }

    void updateValueRec(long long start, long long end, long long i, long long diff, long long startIndex)
    {
        if (i < start || i > end)
            return;
        segT[startIndex] = segT[startIndex] + diff;
        if (end != start)
        {
            long long mid = MidVal(start, end);
            updateValueRec(start, mid, i, diff, 2 * startIndex + 1);
            updateValueRec(mid + 1, end, i, diff, 2 * startIndex + 2);
        }
    }
    long long constructRec(long long start, long long end, int startIndex)
    {
        if (start == end)
        {
            segT[startIndex] = array[start];
            return array[start];
        }
        long long mid = MidVal(start, end);
        segT[startIndex] = constructRec(start, mid, startIndex * 2 + 1) +
                           constructRec(mid + 1, end, startIndex * 2 + 2);
        return segT[startIndex];
    }

    long long getSumRec(long long start, long long end, long long queryStart, long long queryEnd, int startIndex)
    {   
       
        if (queryStart <= start && queryEnd >= end)
            return segT[startIndex];
        if (end < queryStart || start > queryEnd)
            return 0;
        long long mid = MidVal(start, end);
        return getSumRec(start, mid, queryStart, queryEnd, 2 * startIndex + 1) +
               getSumRec(mid + 1, end, queryStart, queryEnd, 2 * startIndex + 2);
    }

public:
    SegmentTree(vector<long long> &input)
    {
        n = input.size();
        array = input;
        long long x = (long)(ceil(log2(n)));
        long long max_size = 2 * (long long)pow(2, x) - 1;
        segT.resize(max_size, 0);
        constructRec(0, n - 1, 0);
    }

    void updateValue(long long i, long long new_val)
    {
        if (i < 0 || i > n - 1)
        {
            return;
        }
        long long diff = new_val - array[i];
        array[i] = new_val;
        updateValueRec(0, n - 1, i, diff, 0);
    }

    long long getSum(long long qs, long long qe)
    {
        if (qs < 0 || qe > n - 1 || qs > qe)
        {
            return -1;
        }
        return getSumRec(0, n - 1, qs, qe, 0);
    }

    void setMap(unordered_map<long long, long long> &GemMap)
    {
        GM = GemMap;
    }

    void updateMap(long long a, long long b)
    {
        GM[a - 1] = b;
    }
};

int main()
{
    long long n,k;
    cin>>n>>k;
    vector<long long> vec(n,0);
    vector<long long>output;
    SegmentTree Tree = SegmentTree(vec);
    set<long long> visited;
    for(int i=0; i<k; i++){
        char val;
        cin>>val;
        if (val == 'F')
        {
            long long v;
            cin>>v;
            if (visited.find(v-1)!=visited.end())
            {
                Tree.updateValue(v-1,0);
                visited.erase(v-1);
            }else{
                Tree.updateValue(v-1,1);
                visited.insert(v-1);
            }
        }else if(val == 'C'){
            long long c1,c2;
            cin>>c1>>c2;
            output.push_back(Tree.getSum(c1-1,c2-1));
        }
        
    }
    for(auto &a: output){
        cout<<a<<endl;
    }
}