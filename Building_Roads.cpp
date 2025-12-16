#include<bits/stdc++.h>
using namespace std;

void dfs(long long u, vector<long long>adj[], vector<long long> &vis )
{
    vis[u]=1;
    for(auto v : adj[u])
    {
        if(!vis[v])
        {
            dfs(v,adj,vis);
        }
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long c, r;
    cin>>c >>r;
    vector<long long>adj[c+1];
    long long u;
    long long v;
    for(int i=0; i<r; i++)
    {
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    vector<long long>vis(c+1);
    long long cnt =0;
    vector<vector<long long>>ans;
    dfs(1, adj, vis);
    for(int i=2; i<=c; i++)
    {
        if(!vis[i])
        {
           
            ans. push_back({1,i});
            cnt++;
            dfs(i,adj, vis);
        }
        

    }
   
    cout<<cnt<<endl;
    for(auto v: ans)
    {
        cout<<v[0]<<" "<<v[1]<<endl;
    }
}