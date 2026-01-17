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
const ll MOD=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    vvl dp(1e6+1, vl(2,0));
    while(t--)
    {
        ll n;
        cin>>n;
        dp[n][0]=1;
        dp[n][1]=1;
        for(ll i=n-1;i>=1;i--){
            dp[i][0]= (2ll*dp[i+1][0] + dp[i+1][1])%MOD;
            dp[i][1]= (4ll*dp[i+1][1] + dp[i+1][0])%MOD;
        }
        cout<<(dp[1][0]+dp[1][1])%MOD<<endl;
    }
    return 0;
}