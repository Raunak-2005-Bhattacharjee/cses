#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
vector<ll> divisors(1e6+1,0);

void count_divisors(){
    for(ll i=1;i<=1e6;i++){
        for(ll j=i;j<=1e6;j+=i){
            divisors[j]++;
        }
    }
}

int main()
{
    ll n;
    cin>>n;
    count_divisors();
    while(n--){
        ll x;
        cin>>x;
        ll ans = divisors[x];
        cout<<ans<<endl;
    }
    return 0;
}