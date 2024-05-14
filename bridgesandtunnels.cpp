#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;
class CustomDJ
{
private:
public:
    unordered_map<string, string> p; // Parent of each node
    unordered_map<string, int> maxH; // Rank of each node
    unordered_map<string, int> size;
    // This will recursivley find the value of teh base of the set
    string findsetRescursive(string x)
    {
        if (p[x] == x)
            return x;
        // Path compression to set the parent of teh current set to the base
        p[x] = findsetRescursive(p[x]);
        return p[x];
    }

    // //This will then store them to be updated in a stack does not rely on recursion depth but also is not as fast
    // int findsetStack(int x){
    //     if(p[x]==x) return x;
    //     stack<int> pointerUpdate;
    //     while (p[x]!=x)
    //     {
    //         pointerUpdate.push(x);
    //         x = p[x];
    //     }
    //     int setNumber = x;
    //     while (!pointerUpdate.empty())
    //     {
    //         p[pointerUpdate.top()]= setNumber;
    //         pointerUpdate.pop();
    //     }

    //     return setNumber;
    // }
    // This will merge base on the value of the max height and then adjust the pointer of the parent to the higher value or just adjust
    void merge(string a, string b)
    {
        string x, y;
        // We find teh sets associated with the values passed in to merge
        x = findsetRescursive(a);
        y = findsetRescursive(b);
        // If they are in teh same ste we do nothing
        if (x == y)
            return;
        // we pick to merge based into the larger set
        if (maxH[x] > maxH[y])
        {
            p[y] = x;
            size[x]+=size[y];
        }
        else if (maxH[x] < maxH[y])
        {
            p[x] = y;
            size[y]+=size[x];
        }
        else
        {
            p[x] = y;
            maxH[y]++;
            size[y]+=size[x];
        }
    }

    void makeSet(string x)
    {
        if (p.find(x) == p.end())
        {
            p[x] = x;
            maxH[x] = 0;
            size[x] = 1;
        }
    }
};

// void dfsCheck(string node, set<string> &visit, unordered_map<string, vector<string> > &graph)
// {
//     visit.insert(node);
//     for (auto& n: graph[node])
//     {
//         if (visit.find(n) == visit.end())
//         {
//             dfsCheck(n,visit,graph);
//         }
//     }
// }

int main()
{
    int testCase;
    cin >> testCase;
    unordered_map<string, vector<string> > graph;
    CustomDJ UNF = CustomDJ();
    int maxNodes = 0;
    for (int i = 0; i < testCase; i++)
    {
        set<string> visit;
        string s1, s2;
        cin >> s1 >> s2;
        UNF.makeSet(s1);
        UNF.makeSet(s2);
        UNF.merge(s1,s2);
        int L = UNF.size[UNF.findsetRescursive(s1)];
        cout<<L<<endl;
    }

    return 0;
}