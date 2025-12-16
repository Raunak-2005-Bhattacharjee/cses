#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

class SegmentTree{
public:
    vl seg;

    SegmentTree(ll n, vl &a) {
        seg.resize(4 * n, INT_MAX);
        build(0, 0, n - 1, a);
    }

    void build(ll ind, ll low, ll high, vl &a) {
        if (low == high) {
            seg[ind] = a[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, a);
        build(2 * ind + 2, mid + 1, high, a);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    ll query(ll l, ll h, ll ind, ll low, ll high) {
        if (l > high || h < low)
            return INT_MAX;
        if (low >= l && high <= h)
            return seg[ind];
        ll mid = (low + high) / 2;
        ll left = query(l, h, 2 * ind + 1, low, mid);
        ll right = query(l, h, 2 * ind + 2, mid + 1, high);
        return min(left, right);
    }

    void update(ll k, ll u, ll ind, ll low, ll high, vl &a)
    {
        if (low == high)
        {
            seg[ind] = u;
            a[k]=u;
            return;
        }
        ll mid = (low + high) / 2;
        if (k <= mid)
            update(k, u, 2 * ind + 1, low, mid, a);
        else
            update(k, u, 2 * ind + 2, mid + 1, high, a);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};
int main()
{
    ll n, q;
    cin >> n >> q;
    vl a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    SegmentTree st(n, a);
    vector<pair<ll, ll>> queries(q);
    for (ll i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;
        queries[i].first = x - 1;
        queries[i].second = y - 1;
    }
    for (ll i = 0; i < q; i++)
    {
        ll ans = st.query(queries[i].first, queries[i].second, 0, 0, n - 1);
        cout << ans << endl;
    }
    return 0;
}