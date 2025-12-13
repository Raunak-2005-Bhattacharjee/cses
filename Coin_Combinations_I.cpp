#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define all(x) (x).begin(), (x).end()
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, x;
    cin >> n >> x;
    vl a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    vl dp(x+1, 0);
    dp[0] = 1;
    for (ll j=1; j<=x; j++)
    {
        ll ans = 0;
        for (auto it : a)
        {
            if (j >= it)
                ans = (ans+dp[j-it])%mod;
        }
        dp[j] = ans;
    }
    cout << dp[x] << endl;
    return 0;
}