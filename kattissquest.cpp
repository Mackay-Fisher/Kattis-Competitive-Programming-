#include<iostream>
#include <set>
#include<vector>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long numInputs;
    cin >> numInputs;
    vector<long long> outputs(0);
    multiset<pair<long long,long long> > checkQs;
    for(long long i=0; i<numInputs; i++){
        string com;
        cin>>com;
        if(com=="add"){
            long long energy,gold;
            cin>>energy>>gold;
            checkQs.insert(make_pair(-energy,-gold));
        }
        if(com=="query"){
            long long testEnergy;
            cin>>testEnergy;
            long long totalGold = 0;
            auto it = checkQs.lower_bound(make_pair(-testEnergy,INT32_MIN));
            while (it!=checkQs.end()&&testEnergy>0)
            {
                if(testEnergy>=-1*(it->first)){
                    totalGold+=-1*(it->second);
                    testEnergy-=-1*(it->first);
                    checkQs.erase(it);
                    it = checkQs.lower_bound(make_pair(-testEnergy,INT32_MIN));
                }else{
                    it++;
                }
                
            }
            outputs.push_back(totalGold);
        }
    }
    for(auto& v: outputs){
        cout<<v<<"\n";
    }
}