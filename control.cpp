#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;
class CustomDJ
{
private:
public:
    unordered_map<int, int> p; // Parent of each node
    unordered_map<int, int> maxH; // Rank of each node
    unordered_map<int, int> size;
    // This will recursivley find the value of teh base of the set
    int findsetRescursive(int x)
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
    void merge(int a, int b)
    {
        int x, y;
        // We find teh sets associated with the values passed in to merge
        x = findsetRescursive(a);
        y = findsetRescursive(b);
        // If they are in teh same ste we do nothing
        if (x == y)
            return;
        // we pick to merge based into the larger set
            p[x] = y;
            size[y]+=size[x];
        // if (maxH[x] > maxH[y])
        // {
        //     p[y] = x;
        //     size[x]+=size[y];
        // }
        // else if (maxH[x] < maxH[y])
        // {
        //     p[x] = y;
        //     size[y]+=size[x];
        // }
        // else
        // {
           
        // }
    }

    void makeSet(int x)
    {
        if (p.find(x) == p.end())
        {
            p[x] = x;
            size[x]=1;
        }
    }
};

int main()
{
    int test;
    cin >> test;
    int mergeCount = 0;
    CustomDJ UNF = CustomDJ();
    for(int i=0; i<test; i++){
        int numI;
        cin>>numI;
        bool merge = false;
        vector<int> vb;
        set<int> uniqueP;
        for(int j=0; j<numI; j++){
            int a;
            cin>>a;
            UNF.makeSet(a);
            vb.push_back(a);
        }
        for (int j=0; j<numI; j++)
        {
            uniqueP.insert(UNF.findsetRescursive(vb[j]));
        }
        int sizeParents=0;

        for(auto &a:uniqueP){
            sizeParents+=UNF.size[UNF.findsetRescursive(a)];
        }
        if (sizeParents <= numI)
        {
            merge = true;
            mergeCount++;
        }
        if (merge)
        {
            for (int j=0; j<vb.size(); j++)
            {
                UNF.merge(vb[0],vb[j]);
            }
        }
    }
    cout<<mergeCount<<endl;
}