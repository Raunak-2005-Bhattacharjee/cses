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
    ll n,m;
    cin>>n>>m;
    vvl edges(m,vl(3));
    vl dist(n+1, 0);
    vl parent(n+1);
    rep(i,0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        edges[i][0]=a;
        edges[i][1]=b;
        edges[i][2]=c;
    }
    rep(i,1,n){
        for(auto it: edges){
            ll a=it[0];
            ll b=it[1];
            ll wt=it[2];
            if(dist[a]+wt<dist[b]){
                dist[b]= dist[a]+wt;
                parent[b]=a;
            }
        }
    }
    ll lastupdated=-1;
    for(auto it: edges){
        ll a=it[0];
        ll b=it[1];
        ll wt=it[2];
        if(dist[a]+wt<dist[b]){
            dist[b]= dist[a]+wt;
            parent[b]=a;
            lastupdated=b;
        }
    }
    if(lastupdated==-1){
        cout<<"NO"<<endl;
        return 0;
    }
    rep(i,0,n)
        lastupdated=parent[lastupdated];
    vl ans;
    ll temp=parent[lastupdated];
    ans.push_back(lastupdated);
    while(temp!=lastupdated){
        ans.push_back(temp);
        temp=parent[temp];
    }
    ans.push_back(lastupdated);
    reverse(all(ans));
    cout<<"YES"<<endl;
    printarr(ans);
    return 0;
}