#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
#include<unordered_set>
using namespace std;
void printStringdfs(int &node, vector<string> &strings,unordered_map<int, vector<int> > &nextN){
    cout<<strings[node];
    for(int i=0; i<nextN[node].size(); i++){
        printStringdfs(nextN[node][i],strings,nextN);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int numberStrings;
    cin>>numberStrings;
    cin.ignore();
    vector<string> strings(numberStrings);
    unordered_map<int, vector<int> > nextIndx;
    unordered_set<int> findset;
    for (int i = 0; i < numberStrings; i++) {
        getline(cin,strings[i]);
        findset.insert(i);
    }
    
    for (int j = 0; j < numberStrings- 1; j++) {
        int ind1, ind2;
        cin >> ind1 >> ind2;
        --ind1;
        --ind2;
        if (findset.find(ind2)!=findset.end())
        {
            findset.erase(ind2);
        }
        nextIndx[ind1].push_back(ind2);
        
    }
    int startNode = *findset.begin();
    printStringdfs(startNode,strings,nextIndx);
    cout<<"\n";
    return 0;
}