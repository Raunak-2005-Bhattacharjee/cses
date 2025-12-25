#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
const ll MOD = 1e9+7;

ll f(ll i, ll money, ll n, ll x, vector<pair<ll,ll>> &books, vector<vl> &dp){
    if(i==0)
        return 0;
    if(dp[i][money] != -1)
        return dp[i][money];
    ll nottake= f(i-1, money, n, x, books, dp);
    ll take=0;
    if(money-books[i-1].first >= 0)
        take= books[i-1].second+ f(i-1, money-books[i-1].first, n, x, books, dp);
    return dp[i][money] = max(take, nottake);
}

int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll> price(n), pages(n);
    for (ll i=0; i<n; i++) 
        cin>>price[i];
    for (ll i=0; i<n; i++) 
        cin>>pages[i];

    vector<pair<ll,ll>> books(n);
    for (ll i = 0; i < n; i++)
        books[i] = {price[i], pages[i]};
    vl prev(x+1), curr(x+1);
    // ll ans= f(n, x, n, x, books, dp);
    // cout<<ans<<endl;

    for(ll i=1; i<=n; i++){
        for(ll money=0; money<=x; money++){
            ll nottake= prev[money];
            ll take=0;
            if(money-books[i-1].first >= 0)
                take= books[i-1].second+ prev[money-books[i-1].first];
            curr[money] = max(take, nottake);
        }
        prev=curr;
    }
    cout<<curr[x]<<endl;
    return 0;
}