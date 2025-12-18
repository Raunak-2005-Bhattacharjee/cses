#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll x,n;
    cin>>x>>n;
    vl a(n);
    for(ll i=0; i<n; i++)
        cin>>a[i];
    set<pair<ll,ll>> s;
    multiset<ll, greater<ll>> ms;
    s.insert({0,x});
    ms.insert(x);
    for(ll i=0; i<n; i++){
        auto y = *(--(s.upper_bound({a[i],0})));
        s.erase(y);
        s.insert({y.first, a[i]});
        s.insert({a[i], y.second});
        ms.erase(ms.find(y.second-y.first));
        ms.insert(a[i]-y.first);
        ms.insert(y.second-a[i]);
        cout<<*(ms.begin())<<" ";
    }
    cout<<endl;
    return 0;
}