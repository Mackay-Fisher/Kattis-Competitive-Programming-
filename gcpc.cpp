#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    long long numTeams;
    cin >> numTeams;
    long long numInput;
    cin >> numInput;
    vector<pair<long long, long long> > input;
    for (long long i = 0; i < numInput; i++)
    {
        long long a, b;
        cin >> a >> b;
        input.push_back(make_pair(a, b));
    }
    // for (auto &a: input)
    // {
    //     cout<<a.first<<" "<<a.second<<endl;
    // }
    
    vector<pair<long long, long long> > teams2;
    for (long long i = 0; i < numTeams; i++)
    {
        teams2.push_back(make_pair(0, 0));
    }
    set<long long> teamsAbove;
    for (auto &t : input)
    {
        teams2[t.first - 1].first += 1;
        teams2[t.first - 1].second += t.second;
        if (t.first == 1)
        {
            vector<long long> removeIndx;
            for (auto &a : teamsAbove)
            {

                if (teams2[a].first < teams2[0].first || (teams2[a].first == teams2[0].first && teams2[a].second >= teams2[0].second))
                {
                    removeIndx.push_back(a);
                }
            }
            for (auto &z : removeIndx)
            {
                teamsAbove.erase(z);
            }
        }
        else
        {
            if (teams2[t.first-1].first > teams2[0].first || (teams2[t.first-1].first == teams2[0].first && teams2[t.first-1].second < teams2[0].second))
            {
                teamsAbove.insert(t.first-1);
            }
        }
        cout << teamsAbove.size()+1 << endl;
    }
}