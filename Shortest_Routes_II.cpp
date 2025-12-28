#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define printarr(arr) for(auto &x: arr) cout<<x<<" "; cout<<endl;
int main()
{
    ll n,m,q;
    cin>>n>>m>>q;
    vvl adjmat(n+1, vl(n+1, 1e16));
    rep(i,0,n+1)
        adjmat[i][i]=0;
    rep(i,0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        adjmat[a][b] = min(adjmat[a][b], c);
        adjmat[b][a] = min(adjmat[b][a], c);

    }
    vector<pll> queries(q);
    rep(i,0,q)
        cin>>queries[i].first>>queries[i].second;
    rep(key,1,n+1){
        rep(i,1,n+1){
            rep(j,1,n+1){
                adjmat[i][j] = min(adjmat[i][j], adjmat[i][key]+adjmat[key][j]);
            }
        }
    }
    rep(i,0,n+1){
        rep(j,0,n+1)
            if(adjmat[i][j] == 1e16)
                adjmat[i][j]=-1;
    }
    rep(i,0,q)
        cout<<adjmat[queries[i].first][queries[i].second]<<endl;
    return 0;
}