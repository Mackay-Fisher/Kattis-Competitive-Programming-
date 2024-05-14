#include <unordered_map>
#include <set>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        unordered_map<string, set<string> > connectionsF;
        unordered_map<string, set<string> > connectionsL;
        map<string, set<string> > FinalConnections;
        int numP;
        cin >> numP;
        for (int j = 0; j < numP; j++)
        {
            string parent;
            cin >> parent;
            int val;
            cin >> val;
            for (int z = 0; z < val; z++)
            {
                string temp;
                cin >> temp;
                connectionsF[temp].insert(parent);
            }
            cin >> val;
            for (int z = 0; z < val; z++)
            {
                string temp;
                cin >> temp;
                connectionsL[temp].insert(parent);
            }
        }
        for (auto &a : connectionsF)
        {
            for(auto c: connectionsL){
                if (a.second == c.second)
                {
                    FinalConnections[a.first].insert(c.first);
                }
                
            }
        }

        for (auto &a : FinalConnections)
        {
            for (auto &b : a.second)
            {
                cout <<"("<<a.first<<", "<<b<<")"<<endl;
            }
        }
        if (i<num-1)
        {
            cout<<endl;
        }
    }
}