#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define inputarr(arr) for(auto &x: arr) cin>>x;
#define printarr(arr) for(auto &x: arr) cout<<x<<" "; cout<<endl;

ll n;

ll f(ll i, ll prev, vl &a, vvl &dp){
    if(i==n)
        return 0;
    if(dp[i][prev+1]!= -1)
        return dp[i][prev+1];
    ll take=0;
    if(prev==-1 || a[prev]<a[i])
        take= 1+ f(i+1,i,a,dp);
    ll nottake= f(i+1,prev,a,dp);
    return dp[i][prev+1]= max(take,nottake);
}

int main()
{
    cin>>n;
    vl a(n);
    vvl dp(n+1, vl(n+1, 0));
    inputarr(a);
    // ll ans= f(0,-1,a, dp);
    // cout<<ans<<endl;

    for(ll ind=n-1; ind>=0; ind--){
        for(ll prev=ind-1; prev>=-1; prev--){
            ll take=0;
            if(prev==-1 || a[prev]<a[ind])
                take= 1+ dp[ind+1][ind+1];
            ll nottake= dp[ind+1][prev+1];
            dp[ind][prev+1]= max(take,nottake);
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}