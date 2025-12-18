#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
const ll MOD = 1e9+7;

ll fastpow(ll a, ll b){
    if(b==0)
        return 1;
    ll half= fastpow(a, b/2);
    half=(half*half)%MOD;
    if(b%2==1)
        half= (half*a)%MOD;
    return half;
}

ll inverse(ll a){
    return fastpow(a, MOD-2);
}

int main()
{
    ll n;
    cin>>n;
    if(n%2==1){
        cout<<"0"<<endl;
        return 0;
    }
    n/=2;
    vl fact(2*n+1), invfact(n+1);
    fact[0]=1;
    for(ll i=1; i<=2*n; i++)
        fact[i]=(i*fact[i-1])%MOD;
    invfact[n] = inverse(fact[n]);
    for(ll i=n-1; i>=0; i--)
        invfact[i]= (invfact[i+1]*(i+1))%MOD;
    ll ans=fact[2*n];
    ans= (ans*invfact[n])%MOD;
    ans= (ans*invfact[n])%MOD;
    ans= (ans*inverse(n+1))%MOD;
    cout<<ans<<endl;
    return 0;
}