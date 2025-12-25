#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

ll bfs(ll i, ll n, vector<vl> &adj, vl &dist){
    ll startv=i;
    dist[startv]=0;
    ll maxdist=0;
    ll endv=startv;
    queue<ll> q;
    q.push(startv);
    while(!q.empty()){
        ll node= q.front();
        q.pop();
        for(auto it: adj[node]){
            if(dist[it] != -1) continue;

            dist[it] = 1+dist[node];
            q.push(it);
            if(dist[it] > maxdist){
                maxdist=dist[it];
                endv=it;
            }
        }
    }
    return endv;
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
    vl dist(n+1, -1), distu(n+1, -1), distv(n+1, -1);
    ll u= bfs(1, n, adj, dist);
    fill(dist.begin(), dist.end(), -1);

    ll v= bfs(u, n, adj, distu);
    ll w= bfs(v, n, adj, distv);

    for(ll i=1; i<=n; i++)
        cout<<max(distu[i], distv[i])<<" ";
    cout<<endl;
    return 0;
}