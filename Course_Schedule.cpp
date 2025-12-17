#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

void bfs(vl &indeg, vl &ans, vector<vl> adj, ll n){
    queue<ll> q;
    for(ll i=1; i<=n; i++){
        if(indeg[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        ll x = q.front();
        q.pop();
        ans.push_back(x);
        for(auto it: adj[x]){
            indeg[it]--;
            if(indeg[it] == 0)
                q.push(it);
        }
    }
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vl> adj(n+1);
    
    vl ans;
    vl indeg(n+1);
    for(ll i=0; i<m; i++){
        ll a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    bfs(indeg, ans, adj, n);
    if(ans.size() < n)
        cout<<"IMPOSSIBLE"<<endl;
    else{
        for(ll i=0; i<n; i++)
            cout<<ans[i]<<" ";
    }
    return 0;
}