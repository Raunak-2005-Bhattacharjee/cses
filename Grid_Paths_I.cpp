#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
const ll MOD = 1e9 + 7;

bool isvalid(ll i, ll j, ll n, vector<vector<char>> &grid)
{
    return (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] != '*');
}

ll f(ll i, ll j, ll n, vector<vector<char>> &grid, vector<vl> &dp)
{
    if (i == n - 1 && j == n - 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    ll down = 0, right = 0;
    if (isvalid(i, j + 1, n, grid))
        right = f(i, j + 1, n, grid, dp);
    if (isvalid(i + 1, j, n, grid))
        down = f(i + 1, j, n, grid, dp);
    return dp[i][j] = (down + right) % MOD;
}

int main()
{
    ll n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vl> dp(n, vl(n, 0));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> grid[i][j];
    if (grid[0][0] == '*')
    {
        cout << 0 << endl;
        return 0;
    }
    // ll ans=f(0,0,n,grid, dp);
    // cout<<ans<<endl;
    dp[n - 1][n - 1] = 1;
    for (ll i = n - 1; i >= 0; i--)
    {
        for (ll j = n - 1; j >= 0; j--)
        {
            if(grid[i][j] == '*'){
                dp[i][j]=0;
                continue;
            }
            if(i==n-1 && j==n-1) continue;
            ll down = 0, right = 0;
            if(j+1<n)
                right= dp[i][j+1];
            if(i+1<n)
                down= dp[i+1][j];
            dp[i][j] = (down + right) % MOD;
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}