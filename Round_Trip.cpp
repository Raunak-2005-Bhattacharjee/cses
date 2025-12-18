#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
ll n, start, ending;

bool dfs(ll i, ll p, vl &vis, vl &parent, vector<vector<ll>> &adj){
    vis[i]=1;
    parent[i]=p;
    for(auto it: adj[i]){
        if(it==p)
            continue;
        if(vis[it]){
            start=it;
            ending=i;
            return true;
        }
        else{
            if(dfs(it,i, vis, parent, adj))
                return true;
        }
    }
    return false;
}

int main()
{
    ll m;
    cin>>n>>m;
    vl vis(n+1);
    vl parent(n+1);
    vector<vector<ll>> adj(n+1);
    for(ll i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool flag=false;
    for(ll i=1; i<=n; i++){
        if(!vis[i]){
            if(dfs(i,-1, vis, parent, adj)){
                flag=true;
                break;
            }
        }
    }
    if(!flag)
        cout<<"IMPOSSIBLE"<<endl;
    else{
        vl ans;
        ll it=ending;
        ans.push_back(start);
        while(it!=start){
            ans.push_back(it);
            it= parent[it];
        }
        ans.push_back(start);
        cout<<(int)ans.size()<<endl;
        for(auto i: ans)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}