#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll n;
    cin>>n;
    ll temp= 2;
    ll ans=0;
    while(n/temp){
        ans+= (n/temp)*(temp/2);
        if(n%temp >= (temp/2)){
            ans+= n%temp - (temp/2) + 1;
        }
        temp*=2;
    }
    if(n%temp >= (temp/2)){
        ans+= n%temp - (temp/2) + 1;
    }
    cout<< ans << endl;
    return 0;
}