#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
const ll MOD = 1e9 + 7;

ll f(ll sum, ll i, vector<vl> &dp, vl &c)
{
    if (i == 0)
    {
        if (sum % c[0] == 0)
            return dp[i][sum] = 1;
        else
            return dp[i][sum] = 0;
    }
    if (dp[i][sum] != -1)
        return dp[i][sum];
    ll take = 0;
    if (sum - c[i] >= 0)
        take = f(sum - c[i], i, dp, c);
    ll nottake = f(sum, i - 1, dp, c);
    return dp[i][sum] = (take + nottake) % MOD;
}

int main()
{
    ll n, x;
    cin >> n >> x;
    vl c(n);
    for (ll i = 0; i < n; i++)
        cin >> c[i];
    vector<vl> dp(n, vl(x + 1, 0));
    // ll ans = f(x, n - 1, dp, c);
    // cout << ans << endl;
    for (ll i = 0; i < n; i++)
        dp[i][0] = 1;
    for (ll j = c[0]; j <= x; j += c[0])
        dp[0][j] = 1;
    for (ll ind = 1; ind < n; ind++)
    {
        for (ll sum = 0; sum <= x; sum++)
        {
            ll take = 0;
            if (sum - c[ind] >= 0)
                take = dp[ind][sum - c[ind]];
            ll nottake = dp[ind - 1][sum];
            dp[ind][sum] = (take + nottake) % MOD;
        }
    }
    cout << dp[n - 1][x] << endl;
    return 0;
}