#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

void bfs(ll n, ll m, vector<vector<ll>> &adj, vector<bool> &vis, vector<ll> &parent){
    queue<ll> q;
    q.push(1);
    vis[1] = true;
    parent[1]=0;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(!vis[v]){
                vis[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

vector<ll> ans(ll n, vector<bool> &vis, vector<ll> &parent){
    if(!vis[n]){
        return {};
    }
    vector<ll> path;
    ll cur=n;
    while(cur != 0){
        path.push_back(cur);
        cur= parent[cur];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    for(ll i=0; i<m; i++)
    {
       ll u,v;
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    vector<bool> vis(n+1,false);
    vector<ll> parent(n+1);
    vl dist(n+1, 0);
    bfs(n,m,adj,vis,parent);
    vector<ll> path = ans(n,vis,parent);
    if(path.size() == 0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<path.size()<<endl;
    for(auto v: path){
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}