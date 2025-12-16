#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll n;
    cin >> n;
    queue<ll> q;
    for (ll i = 1; i <= n; i++)
        q.push(i);
    vl ans;
    int counter = 0;
    while (!q.empty())
    {
        if (counter == 0)
        {
            ll x = q.front();
            q.pop();
            q.push(x);
            counter = 1;
        }
        else
        {
            ll x = q.front();
            q.pop();
            ans.push_back(x);
            counter = 0;
        }
    }
    for (ll i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}