#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

ll power(ll n){
    if(n==1) return 2;
    if(n%2 ==0)
        return (power(n/2)*power(n/2))%mod;
    else    
        return (2*power(n/2)*power(n/2))%mod;
}

int main()
{
    ll n;
    cin>>n;
    ll ans = power(n);
    cout<<ans<<endl;
    return 0;
}