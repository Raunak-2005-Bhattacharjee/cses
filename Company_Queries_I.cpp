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

ll backtrack(ll n, ll k, vl &adj){
    if(n<=0)
        return -1;
    if(k==0)
        return n;
    if(n==1)
        return -1;
    return backtrack(adj[n],k-1,adj);
}

int main()
{
    ll n,q;
    cin>>n>>q;
    vl adj(n+1);
    rep(i,1,n){
        ll a;
        cin>>a;
        adj[a]=i;
    }
    rep(i,0,q){
        ll x,k;
        cin>>x>>k;
        cout<<backtrack(x,k,adj)<<endl;
    }

    return 0;
}