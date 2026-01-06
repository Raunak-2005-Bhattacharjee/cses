#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

ll lcs(ll i, ll j,vl &a, vl &b, vector<vector<ll>> &dp){
    if(i<0 || j<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(a[i] == b[j]){
        dp[i][j]=  1+lcs(i-1,j-1,a,b,dp);
    }
    else
        dp[i][j]= max(lcs(i-1,j,a,b,dp), lcs(i,j-1,a,b,dp));
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
    // ll length = lcs(n-1, m-1, a, b, dp);
    // cout<<length<<endl;

    if(a[0]==b[0]){
        dp[0][0]=1;
    }
    for(ll i=1; i<n; i++){
        if(b[0]==a[i])
            dp[i][0]=1;
        else    
            dp[i][0]=dp[i-1][0];
    }
    
    for(ll i=1; i<m; i++){
        if(a[0]==b[i])
            dp[0][i]=1;
        else
            dp[0][i]= dp[0][i-1];
    }

    for(ll i=1; i<n; i++){
        for(ll j=1; j<m; j++){
            if(a[i] == b[j]){
                dp[i][j]=  1+dp[i-1][j-1];
            }
            else
                dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[n-1][m-1]<<endl;
    ll i=n-1,j=m-1;
    vector<ll> ans;
    while(i>=0 && j>=0){
        if(a[i]==b[j]){
            ans.push_back(a[i]);
            i--;
            j--;
        }
        else if(i>0 && dp[i-1][j]>= dp[i][j-1])
            i--;
        else    
            j--;
    }
    reverse(ans.begin(),ans.end());
    for(ll i=0; i<(int)ans.size(); i++)
        cout<<ans[i]<<" ";
    
    cout<<endl;
    return 0;
}