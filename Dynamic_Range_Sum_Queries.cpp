#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

class SegmentTree
{
public:
    vl seg;

    SegmentTree(ll n, vl &a)
    {
        seg.resize(4 * n, 0);
        build(0, 0, n - 1, a);
    }

    void build(ll ind, ll low, ll high, vl &a)
    {
        if (low == high)
        {
            seg[ind] = a[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, a);
        build(2 * ind + 2, mid + 1, high, a);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    ll query(ll l, ll h, ll ind, ll low, ll high)
    {
        if (l > high || h < low)
            return 0;
        if (low >= l && high <= h)
            return seg[ind];
        ll mid = (low + high) / 2;
        ll left = query(l, h, 2 * ind + 1, low, mid);
        ll right = query(l, h, 2 * ind + 2, mid + 1, high);
        return left + right;
    }

    void update(ll k, ll u, ll ind, ll low, ll high, vl &a)
    {
        if (low == high)
        {
            seg[ind] = u;
            a[k] = u;
            return;
        }
        ll mid = (low + high) / 2;
        if (k <= mid)
            update(k, u, 2 * ind + 1, low, mid, a);
        else
            update(k, u, 2 * ind + 2, mid + 1, high, a);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};

int main()
{
    ll n, q;
    cin >> n >> q;
    vl a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<ll>> queries(q, vector<ll>(3));
    for (ll i = 0; i < q; i++)
    {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }
    SegmentTree st(n, a);
    for (ll i = 0; i < q; i++)
    {
        if (queries[i][0] == 1)
            st.update(queries[i][1] - 1, queries[i][2], 0, 0, n - 1, a);
        else
            cout << st.query(queries[i][1] - 1, queries[i][2] - 1, 0, 0, n - 1) << endl;
    }
    return 0;
}