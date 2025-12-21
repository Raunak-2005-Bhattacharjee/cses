#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

ll f(ll i, ll sum1, ll sum2, ll n, vl &p){
    if(i==n)
        return abs(sum1-sum2);
    ll left = f(i+1, sum1+p[i], sum2, n, p);
    ll right = f(i+1, sum1, sum2+p[i], n, p);
    return min(left, right);
}

int main()
{
    ll n;
    cin>>n;
    vl p(n);
    for(ll i=0; i<n; i++)
        cin>>p[i];
    ll sum1=0,sum2=0;
    ll ans= f(0, sum1, sum2, n, p);
    cout<<ans<<endl;
    return 0;
}