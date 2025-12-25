#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
const ll MOD = 1e9 + 7;

int main()
{
    ll n, x;
    cin >> n >> x;
    vl c(n);
    for (ll i = 0; i < n; i++)
        cin >> c[i];
    vector<ll> next(x + 1, 0), curr(x + 1, 0);
    next[0] = 1;
    for (ll i = n - 1; i >= 0; i--)
    {
        curr[0] = 1; 

        for (ll sum = 1; sum <= x; sum++)
        {
            ll nottake = next[sum];
            ll take = 0;
            if (sum >= c[i])
                take = curr[sum - c[i]];

            curr[sum] = (take + nottake) % MOD;
        }

        next = curr;
    }
    cout << next[x] << endl;
    return 0;
}