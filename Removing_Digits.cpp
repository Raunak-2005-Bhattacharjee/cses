#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

ll ans = 1e18;

int main()
{
    ll n;
    cin>>n;
    vl dp(n+1, 1e18);
    dp[0]=0;
    for(ll x=1; x<=n; x++){
        string num= to_string(x);
        for(int i=0; i<num.size(); i++){
            int d= num[i]-'0';
            if(d!=0)
                dp[x] = min(dp[x], 1+dp[x-d]);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}