#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
const ll MOD = 1e9+7;
const ll SIZE = 2e6+1;

ll fastpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll half = fastpow(a, b / 2);
    half = (half * half) % MOD;
    if (b % 2 == 1)
        half = (half * a) % MOD;
    return half;
}

ll inverse(ll a)
{
    return fastpow(a, MOD - 2);
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vl fact(SIZE), invfact(SIZE);
    fact[0] = 1;
    for (ll i = 1; i <= SIZE; i++)
        fact[i] = (i * fact[i - 1]) % MOD;
    invfact[SIZE] = inverse(fact[SIZE]);
    for (ll i = SIZE - 1; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    ll ans= fact[n+m-1];
    ans= (ans*invfact[m])%MOD;
    ans= (ans*invfact[n-1])%MOD;
    cout<<ans<<endl;
    return 0;
}