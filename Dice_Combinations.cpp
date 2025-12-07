#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1, 0);
    dp[0]=1;
    for(int j=1; j<=n; j++){
        int a=0;
        for(int i=1; i<=6; i++){
            if(j-i >= 0)
                a= (a+dp[j-i])%mod;
        }
        dp[j]=a;
    }
    cout<<dp[n]<<endl;
    return 0;
}