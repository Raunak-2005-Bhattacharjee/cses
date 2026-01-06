#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define inputarr(arr) for(auto &x: arr) cin>>x;
#define printarr(arr) for(auto &x: arr) cout<<x<<" "; cout<<endl;

bool compare(pll a, pll b){
    if(a.first==b.first)
        return a.second>b.second;
    return a.first<b.first;
}

int main()
{
    ll n;
    cin>>n;
    vector<pll> range(n);
    rep(i,0,n)
        cin>>range[i].first>>range[i].second;
    vector<pll> temp;
    temp=range;
    sort(all(temp), compare);
    vl contains(n,0), contained(n,0);
    for(ll i=0; i<n; i++){
        ll l = range[i].first;
        ll r = range[i].second;
        ll pos = (lower_bound(all(temp), pll(l,0)) - temp.begin());
        for(ll j=n-1; j>pos; j--){
            if(temp[j].second <= r){
                contains[i]=1;
                break;
            }
        }
        for(ll j=0; j<n && temp[j].first<=l; j++){
            if(j!=pos && temp[j].second>=r){
                contained[i]=1;
                break;
            }
        }
    }
    printarr(contains);
    printarr(contained);
    return 0;
}