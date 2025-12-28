#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define printarr(arr)     \
    for (auto &x : arr)   \
        cout << x << " "; \
    cout << endl;
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<pll>> adj(n + 1);
    vl dist(n + 1, LLONG_MAX);
    rep(i, 0, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    set<pll> s;
    s.insert({0, 1});
    dist[1] = 0;
    while (!s.empty())
    {
        auto it = *(s.begin());
        ll dis = it.first;
        ll node = it.second;
        s.erase(it);
        for (auto i : adj[node])
        {
            ll adjnode = i.first;
            ll wt = i.second;
            if (dis + wt < dist[adjnode])
            {
                if (dist[adjnode] != 1e9)
                    s.erase({dist[adjnode], adjnode});
                dist[adjnode] = dis + wt;
                s.insert({dist[adjnode], adjnode});
            }
        }
    }
    rep(i, 1, n + 1)
            cout<< dist[i] << " ";
    cout << endl;
    return 0;
}