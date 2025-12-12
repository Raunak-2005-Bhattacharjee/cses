#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
const int SIZE = 2e5+5;
void dfs(int i, map<int, int> &mp, vector<vector<ll>> &adj){
    for(auto it: adj[i]){
        dfs(it, mp, adj);
        mp[i]+= mp[it]+1;
    }
}
int main()
{
    ll n;
    cin>> n;
    vl a(n-1);
    for(int i=0; i<n-1; i++) cin>>a[i];
    vector<vector<ll>> adj(n+1);
    for(int i=0; i<n-1; i++){
        adj[a[i]].push_back(i+2);
    }
    map<int, int> mp;
    dfs(1, mp, adj);
    for(auto it: mp){
        cout<< it.second << " ";
    }
    return 0;
}