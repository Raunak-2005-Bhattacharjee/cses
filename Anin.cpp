#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 +7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    vector<vector<ll>>dp(1e6+1,vector<ll>(2,0));
    while(t--){
        ll n;
        cin >> n;
        dp[n][1]=1;
        dp[n][0]=1;
        for(ll i=n-1; i>=1;i--){
                dp[i][0]=(2*dp[i+1][0]+dp[i+1][ 1])%mod;
                dp[i][1]=(4*dp[i+1][1] +dp[i+1][0])%mod;
            }
        
        cout<<(dp[1][0]+dp[1][1])%mod<<endl;
    }
    }