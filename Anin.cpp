#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1e9 +7;
// ll solve(ll i, ll j, vector<vector<char>> &grid, vector<vector<ll>> &dp, ll n){
//     if(i==0 && j==0){
//         if(grid[0][0]=='*')
//         return 0;
//         else
//         return 1;
//     }
//     if(i>=0 && j>=0 && grid[i][j]=='*'){
//         return 0;
//     }
//     if(i<0 || j<0){
//         return 0;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     ll left = solve(i,j-1,grid,dp,n);
//     ll up = solve(i-1,j,grid,dp,n);
//     return dp[n-1][n-1]=left + right;
// }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n,0));
    for(ll i=0; i<n;i++){
        for(ll j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));
    if(grid[0][0]!='*'){
        dp[0][0]=1;
    }
    for(ll i=0; i<n;i++){
        for(ll j=0; j<n; j++){
            if(i == 0 && j == 0) continue;
          if(grid[i][j]=='*'){
           dp[i][j]=0;
           continue;
          }
            ll up=0;
            ll left=0;
           if(j>0)
            left=dp[i][j-1] ;
           if(i>0)
            up= dp[i-1][j];
           dp[i][j]=(left + up)%M;
        }
    }

    cout<<(dp[n-1][n-1])%M;
}