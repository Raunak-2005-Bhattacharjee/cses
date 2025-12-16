#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll n, q;
    cin >> n >> q;
    vl a(n);
    vl pref(n + 1);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        pref[i + 1] = pref[i] ^ a[i];
    }
    for (ll i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;
        cout << (pref[y] ^ pref[x - 1]) << endl;
    }

    return 0;
}