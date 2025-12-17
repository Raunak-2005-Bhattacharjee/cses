#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

bool valid(ll i, ll j, ll n, ll m){
    return (i>=0 && i<n && j>=0 && j<m);
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++)
            cin>>grid[i][j];
    vector<vector<char>> ans(n, vector<char>(m));
    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++){
            set<char> nota;
            nota.insert(grid[i][j]);
            if(valid(i-1, j, n, m))
                nota.insert(ans[i-1][j]);
            if(valid(i, j-1, n, m))
                nota.insert(ans[i][j-1]);
            for(char c='A'; c<='D'; c++){
                if(nota.find(c) == nota.end()){
                    ans[i][j] = c;
                    break;
                }
            }
        }
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++)
            cout<<ans[i][j];
        cout<<endl;
    }
    return 0;
}