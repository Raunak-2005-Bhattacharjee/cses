#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

ll count(ll k){
    ll total= k*k*(k*k-1)/2;
    ll attack= 4*(k-1)*(k-2);
    return total-attack;
}

int main()
{
    ll n;
    cin>>n;
    for(ll i=1; i<=n; i++){
        ll ans=count(i);
        cout<<ans<<endl;
    }
    return 0;
}