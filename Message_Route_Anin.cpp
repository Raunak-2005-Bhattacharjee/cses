#include<bits/stdc++.h>
using namespace std;
using ll= long long;


bool bfs(vector<bool> &vis, vector<ll>adj[],vector<ll> &par,ll n, vector<ll> &path)
{
    vis[1] =true;
    queue<ll>q;
    q.push(1);
    par[1]=0;
    while(!q.empty())
    {
        ll c = q.front();
        q.pop();

        if(c == n)
        {
            ll cur=n;
            while(cur!=0)
            {
                path.push_back(cur);
                cur=par[cur];
            }
             return true;
        }
        for(auto v : adj[c])
        {
            if(!vis[v])
            {
                par[v]=c;
                q.push(v);
                vis[v]=true;
            }
        }
       
    
    }
    return false;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll>adj[n+1];
    for(ll i =0; i<m; i++ )
    {
        ll u,v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>vis(n+1);
    vector<ll>par(n+1);
    vector<ll>path;
    
        if(bfs(vis,adj,par,n,path))
        {
            cout<<path.size()<<endl;
            reverse(path.begin(),path.end());
            for(auto v : path)
            {
                cout<<v<<" ";
            }


        }
        else{
            cout<<"IMPOSSIBLE";
        }
    }