#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

ll f(ll sum, vl &c, ll n, vl &dp)
{
    if (sum == 0)
        return 0;
    if (dp[sum] != 1e9)
        return dp[sum];
    for (ll i = 0; i < n; i++)
        if (sum - c[i] >= 0)
            dp[sum] = min(dp[sum], 1 + f(sum - c[i], c, n, dp));
    return dp[sum];
}

int main()
{
    ll n, x;
    cin >> n >> x;
    vl c(n);
    for (ll i = 0; i < n; i++)
        cin >> c[i];
    vl dp(x + 1, 1e9);
    // ll ans = f(x,c,n,dp);
    dp[0] = 0;
    for (ll sum = 0; sum <= x; sum++)
    {
        for (ll i = 0; i < n; i++)
            if (sum - c[i] >= 0)
                dp[sum] = min(dp[sum], 1 + dp[sum-c[i]]);
    }
    cout << (dp[x]==1e9 ? -1 : dp[x]) << endl;
    // cout<<ans<<endl;
    return 0;
}