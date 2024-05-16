#include<vector>
#include<stack>
#include<string>
#include<iostream>
#include<set>
#include<unordered_map>
#include <iomanip>
using namespace std;
int main(){
    string s;
    
    long long totalShares = 0;
    double averageCost = 0;
    while (cin>>s)
    {
        if (s=="buy")
        {
            long long a,b;
            cin>>a>>b;
            double curValue = totalShares*averageCost;
            double nextVal = a*b;
            totalShares+=a;
            curValue = (curValue + nextVal)/totalShares;
            averageCost = curValue;
            // cout<<"buy "<<totalShares<<" "<<averageCost<<endl;
        }else if(s=="split"){
            long long x;
            cin>>x;
            totalShares*=x;
            averageCost = averageCost/x;
            // cout<<"Split"<<totalShares<<" "<<averageCost<<endl;
        }else if(s=="merge"){
            long long b;
            cin>>b;
            totalShares /= b;
            averageCost = averageCost * b;
            // cout<<"Merge"<<totalShares<<" "<<averageCost<<endl;
        }else if(s=="sell"){
            long long a,b;
            cin>>a>>b;
            totalShares-=a;
            // cout<<"Sell"<<totalShares<<" "<<averageCost<<endl;
        }else if(s=="die"){
            long long a;
            cin>>a;
            if (a>averageCost)
            {
                double val = a - averageCost;
                double profit = totalShares*( a - (val)*.3);
                cout<<fixed<<setprecision(8)<<profit<<endl;
            }else{
                double profit =  a*totalShares;
                cout<<fixed<<setprecision(8)<<profit<<endl;
            }
            // cout<<"Total"<<totalShares<<" "<<averageCost<<endl;
        }
        
    }
    
}