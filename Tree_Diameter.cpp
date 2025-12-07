#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &dist){
    for(auto child: adj[node]){
        if(child != parent){
            dist[child] = 1+dist[node];
            dfs(child, node, adj, dist);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int, int>> edges(n-1);;
    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        edges[i] = {a, b};
    }
    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n+1);
    dfs(1, 0, adj, dist);

    int farthestnode;
    int maxdist = -1e9;
    for(int i=1; i<=n; i++){
        if(dist[i] > maxdist){
            maxdist = dist[i];
            farthestnode = i;
        }
    }
    for (int i = 0; i <= n; i++) {
        dist[i] = 0;
    }
    dfs(farthestnode, 0, adj, dist);
    for(int i=1; i<=n; i++){
        maxdist = max(maxdist, dist[i]);
    }
    cout<<maxdist<<endl;
    return 0;
}