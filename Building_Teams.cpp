#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

bool bipartite(ll i, ll n, vector<vector<ll>> &adj, vl &color, vl &vis){
    queue<ll> q;
    q.push(i);
    vis[i] = 1;
    
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                color[it] = !color[node];
                q.push(it);
            }
            else if(color[it] == color[node])
                return false;
        }
    }
    return true;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    for(ll i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vl color(n+1, -1);
    vl vis(n+1, 0);
    for(ll i=1; i<=n; i++){
        if(!vis[i]){
            color[i] = 0;
            if(!bipartite(i, n, adj, color, vis)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(ll i=1; i<=n; i++){
        cout<<color[i]+1<<" ";
    }
    cout<<endl;
    return 0;
}