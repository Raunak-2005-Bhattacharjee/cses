#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<ll, ll> mp;
    ll l = 0;
    ll r = 0;
    ll ans = 0;
    while (r < n)
    {
        if (mp.find(arr[r]) == mp.end())
        {
            mp[arr[r]]++;
            ans += (r - l + 1);
            r++;
        }
        else
        {

            if (mp[arr[r]] <= k)
            {
                mp[arr[r]]++;
                while (mp[arr[r]] > k)
                {
                    if (arr[l] == arr[r])
                    {
                        mp[arr[r]]--;
                    }
                    l++;
                }
            }
            else
            {

                ans += (r - l + 1);
                r++;
            }
        }
    }
    cout << ans;
}