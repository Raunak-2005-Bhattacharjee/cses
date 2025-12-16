#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll n,q;
    cin>>n>>q;
    vl arr(n);
    vl pre(n+1);
    for(ll i=0; i<n; i++){
        cin>>arr[i];
        pre[i+1] = pre[i]+arr[i];
    }
    vector<pair<ll,ll>> que(q);
    for(ll i=0; i<q; i++)
        cin>>que[i].first>>que[i].second;
    for(ll i=0; i<q; i++)
        cout<<pre[que[i].second]-pre[que[i].first-1]<<endl;
    return 0;
}