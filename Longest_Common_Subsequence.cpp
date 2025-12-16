#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

ll lcs(ll i, ll j,vl &a, vl &b, vector<vector<ll>> &dp, vl &ans){
    if(i<0 || j<0) return 0;

    if(dp[i][j] != 0) return dp[i][j];

    if(a[i] == b[j]){
        dp[i][j]=  1+lcs(i-1,j-1,a,b,dp,ans);
    }
    else
        dp[i][j]= max(lcs(i-1,j,a,b,dp,ans), lcs(i,j-1,a,b,dp,ans));
    return dp[i][j];

}

int main()
{
    ll n,m;
    cin>>n>>m;
    vl a(n);
    vl b(m);
    for(ll i=0; i<n; i++)
        cin>>a[i];
    for(ll i=0; i<m; i++)
        cin>>b[i];
    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    vl ans;
    ll length = lcs(n-1, m-1, a, b, dp, ans);
    cout<<length<<endl;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}