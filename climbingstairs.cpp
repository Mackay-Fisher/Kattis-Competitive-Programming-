#include<iostream>
#include<vector>
using namespace std;
int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    long long total = c;
    total+= abs(b-c);
    long long valToReach = a - total;
    while (valToReach > 0)
    {
        valToReach -= 2;
        total+=2;
    }
    total+=b;
    cout<<total<<endl;  
}