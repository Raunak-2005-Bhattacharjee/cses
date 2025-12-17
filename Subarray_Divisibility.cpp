#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll n;
    cin>>n;
    vl pref(n+1);
    unordered_map<ll, ll> mp;
    mp[0]++;
    ll ans=0;
    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        pref[i+1] = ((pref[i]+x)%n+n)%n;
        ans+= mp[pref[i+1]];
        mp[pref[i+1]]++;
    }
    cout<<ans<<endl;
    return 0;
}