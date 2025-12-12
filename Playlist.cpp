#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll n;
    cin>>n;
    vl k(n);
    for(int i=0; i<n; i++)
        cin>>k[i];
    map<ll, ll> mp; 
    ll ans=0;
    ll i=0;
    for (ll j=0; j<n; j++) {
        if (mp.count(k[j]) && mp[k[j]] >= i) {
            i= mp[k[j]]+1;
        }
        mp[k[j]]= j;
        ans = max(ans, j-i+1);
    }
    cout <<ans << endl;
    return 0;
}