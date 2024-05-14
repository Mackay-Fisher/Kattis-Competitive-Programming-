#include<vector>
#include<stack>
#include<string>
#include<iostream>
#include<set>
#include<unordered_map>
using namespace std;
 
class CustomDJ {
    private:

    public:
    unordered_map<long long, long long> p; // Parent of each node
    // unordered_map<int, int> maxVal; // Rank of each node
    unordered_map<long long, long long> size;
    set<long long> uniqueParents;
    long long  maxValue = 0;
    //This will recursivley find the value of teh base of the set
    long long findsetRescursive(long long x){
        if(p[x]==x) return x;
        //Path compression to set the parent of teh current set to the base
        p[x]=findsetRescursive(p[x]);
        return p[x];
    }

    //This will then store them to be updated in a stack does not rely on recursion depth but also is not as fast
    // int findsetStack(in x){
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
    //This will merge base on the value of the max height and then adjust the pointer of the parent to the higher value or just adjust
    void merge(long long a,long long b){
        long long x,y;
        //We find teh sets associated with the values passed in to merge
        x = findsetRescursive(a);
        y = findsetRescursive(b);
        p[x]=y; 
        maxValue  -= tenVal(size[y]);
        maxValue  -= tenVal(size[x]);
        size[y]+=size[x];
        long long curVal = size[y];
        if(curVal%10!=0){
            curVal += (10-curVal%10);
        }
        uniqueParents.erase(x);
        maxValue += curVal;
    }

    long long tenVal(long long curVal){
        if(curVal%10!=0){
                curVal += (10-curVal%10);
        }
        return curVal;
    }

    void makeSet(long long x, long long  c)
    {
        if (p.find(x) == p.end())
        {
            uniqueParents.insert(x);
            p[x] = x;
            size[x]=c;

            maxValue  += tenVal(c);
        }

    }
};

int main(){
    long long num;
    cin>>num;
    CustomDJ UNF = CustomDJ();
    vector<long long > pass(num);
    vector<long long> order(num);
    long long  maxVal = 0;
    for (long long i = 0; i < num; i++)
    {
        long long  cnum;
        cin>>cnum;
        pass[i]=(cnum);
    }

    
    for (long long i = num-1; i >=0; i--)
    {
        long long cnum;
        cin>>cnum;
        order[i] = cnum;
    }
    vector<long long> holdVal(num,-1);
    set<long long> elmsAdded;
    for ( auto &c: order)
    {
        UNF.makeSet(c-1,pass[c-1]);
        elmsAdded.insert(c-1);
        holdVal[c-1]=pass[c-1];
        long long left = c-2;
        long long right = c;
        if (left>=0 && holdVal[left]!= -1)
        {
            UNF.merge(c-1,left);
        }
        if(right<num && holdVal[right]!=-1){
            UNF.merge(c-1,right);
        }
        //TODO Fix the speed at which I cna capture the values of the input.
        //Find a way to keep track of the unique parents.
        // int local  = 0;
        // for(auto &p : UNF.uniqueParents){
        //     int curVal = UNF.size[p];
        //     if(curVal%10!=0){
        //         curVal += (10-curVal%10);
        //     }
        //     local += curVal;
        // }
        long long  local = UNF.maxValue * UNF.uniqueParents.size();
        maxVal = max(maxVal,local);
    }
    cout<<maxVal<<endl;
}