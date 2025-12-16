#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll n;
    cin>>n;
    vl a(n);
    ll count=0;
    for(ll i=0; i<n; i++)
        cin>>a[i];
    multiset<ll> s;
    for(ll i=0; i<n; i++)
    {
        auto it = s.upper_bound(a[i]);
        if(it==s.end())
        {
            s.insert(a[i]);
            count++;
        }
        else
        {
            s.erase(it);
            s.insert(a[i]);
        }
    }
    cout<<count<<endl;
    return 0;
}