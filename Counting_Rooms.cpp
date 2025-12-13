#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

void dfs(ll r, ll c, ll n, ll m, vector<vector<bool>> &vis, vector<vector<char>> &grid){
    vis[r][c] = true;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    for(int i=0; i<4; i++){
        ll row= r+dr[i];
        ll col= c+dc[i];
        if(row>=0 && row<n && col>=0 && col<m && grid[row][col] != '#'){
            if(!vis[row][col])
                dfs(row, col, n, m, vis, grid);
        }
    }
}

int main()
{
    ll n, m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    ll count=0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j]=='.'){
                dfs(i, j, n, m, vis, grid);
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}