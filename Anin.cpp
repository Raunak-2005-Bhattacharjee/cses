#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, t;
    cin >>n >>t;
    vector<ll>arr(n);
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<ll>dp((t+1),1e9);
    dp[0]= 0;
    for(ll sum=0; sum<=t; sum++){
    for(ll i=0; i<n; i++){
        if(sum>=arr[i]){
            dp[sum]= min(dp[sum],1+dp[sum-arr[i]]);
        }
    }}
    if(dp[t]==1e9){
        cout<<-1<<endl;
    }
    else{
        cout<<dp[t];
    }
    
}