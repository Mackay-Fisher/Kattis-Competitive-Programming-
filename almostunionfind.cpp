#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

class CustomDJ
{
private:
public:
    unordered_map<long long, long long> p;
    unordered_map<long long, long long> size;
    unordered_map<long long, long long> sum;
    unordered_map<long long, set<long long> > MapSet;
    long long findsetRescursive(long long x)
    {
        return p[x];
    }
    void merge(long long a, long long b)
    {
        long long x, y;
        x = findsetRescursive(a);
        y = findsetRescursive(b);
        if (x == y)
        {
            return;
        }
        if (size[x] > size[y])
        {
            size[x] += size[y];
            sum[x] += sum[y];
            for (auto &a : MapSet[y])
            {
                p[a] = x;
                MapSet[x].insert(a);
            }
            MapSet[y].clear();

        }
        else
        {
            size[y] += size[x];
            sum[y] += sum[x];
            for (auto &a : MapSet[x])
            {
                p[a]=y;
                MapSet[y].insert(a);
            }
            MapSet[x].clear();
        }
    }
    void sumVal(long long a)
    {
        long long x = findsetRescursive(a);
        
        // for ( auto &b : MapSet)
        // {
        //     cout<<"parent for "<<b.first<<" = "<<findsetRescursive(b.first)<<endl;
        //     cout << "values assocaited with: " << b.first << " (";
        //     for (auto &a : MapSet[b.first])
        //     {
        //         cout << " " << a;
        //     }
        //      cout << " )" << endl;
        // }
        cout << size[x] << " " << sum[x] << endl;
    }
    void move(long long a, long long b)
    {
        long long x, y;
        x = findsetRescursive(a);
        y = findsetRescursive(b);
        if (x == y)
        {
            return;
        }
        size[x]--;
        sum[x] -= a;
        MapSet[x].erase(a);
        MapSet[y].insert(a);
        size[y]++;
        sum[y] += a;
        p[a] = y;
    }
    void makeSet(long long x)
    {
        if (p.find(x) == p.end())
        {
            MapSet[x].insert(x);
            p[x] = x;
            size[x] = 1;
            sum[x] = x;
        }
    }
};

int main()
{
    long long nextToken;
    set<long long> collectIndex;
    while (cin >> nextToken)
    {
        if (nextToken == -1)
        {
            break;
        }
        if (nextToken != 1 || nextToken != 2 || nextToken != 3)
        {
            CustomDJ UNF = CustomDJ();
            for(int i = 0; i<nextToken; i++){
                UNF.makeSet(i+1);
            }
            long long numTest;
            cin >> numTest;
            for (int i = 0; i < numTest; i++)
            {
                long long opp;
                cin >> opp;
                if (opp == 1)
                {
                    long long a, b;
                    cin >> a >> b;
                    // if(collectIndex.find(a)==collectIndex.end()){
                    //     UNF.makeSet(a);
                    //     collectIndex.insert(a);
                    // }
                    // if(collectIndex.find(b)==collectIndex.end()){
                    //     UNF.makeSet(b);
                    //     collectIndex.insert(b);
                    // }
                    UNF.merge(a, b);
                }
                else if (opp == 2)
                {
                    long long a, b;
                    cin >> a >> b;
                    // if(collectIndex.find(a)==collectIndex.end()){
                    //     UNF.makeSet(a);
                    //     collectIndex.insert(a);
                    // }
                    // if(collectIndex.find(b)==collectIndex.end()){
                    //     UNF.makeSet(b);
                    //     collectIndex.insert(b);
                    // }
                    UNF.move(a, b);
                }
                else if (opp == 3)
                {
                    long long a;
                    cin >> a;
                    // if(collectIndex.find(a)==collectIndex.end()){
                    //     UNF.makeSet(a);
                    //     collectIndex.insert(a);
                    // }
                    UNF.sumVal(a);
                }
            }
        }
    }
}