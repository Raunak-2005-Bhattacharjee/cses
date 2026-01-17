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
int main()
{
    ll a,b;
    cin>>a>>b;
    vvl dp(a+1, vl(b+1, 1e9));
    for(ll i=1; i<=a; i++){
        for(ll j=1; j<=b; j++){
            if(i==j)
                dp[i][j]=0;
            for(ll k=1; k<i; k++)
                dp[i][j]= min(dp[i][j], 1+dp[k][j]+dp[i-k][j]);
            for(ll k=1; k<j; k++)
                dp[i][j]= min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}