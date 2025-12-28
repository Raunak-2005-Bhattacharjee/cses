#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

void dfs1(ll node, ll parent, ll depth, vl &ans, vl &dp, vector<vl> &adj){
    ans[1]+= depth;
    dp[node]=1;
    for(auto it: adj[node]){
        if(it!= parent){
            dfs1(it, node, depth+1, ans, dp, adj);
            dp[node]+= dp[it];
        }
    }
}

void dfs2(ll node, ll parent, vl &ans, vl &dp, vector<vl> &adj, ll n){
    for(auto it: adj[node]){
        if(it!= parent){
            ans[it] = ans[node] + (n-2*dp[it]);
            dfs2(it, node, ans, dp, adj, n);
        }
    }
}

int main()
{
    ll n;
    cin>>n;
    vector<pair<ll, ll>> edges(n-1);;
    for(ll i=0; i<n-1; i++)
    {
        ll a, b;
        cin>>a>>b;
        edges[i] = {a, b};
    }
    vector<vl> adj(n+1);
    for(ll i=0; i<n-1; i++){
        ll u = edges[i].first;
        ll v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vl ans(n+1, 0), dp(n+1, 0);
    dfs1(1, 0, 0, ans, dp, adj);
    dfs2(1, 0, ans, dp, adj, n);
    for(ll i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}