#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
string graycode(ll x, ll n){
    int gc = x^(x>>1);
    string ans = "";
    for(int i=n-1; i>=0; i--) {
        ans+= (gc&(1LL<<i)) ? '1' : '0';
    }
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=0; i<(1ll<<n); i++){
        string ans = graycode(i, n);
        cout<<ans<<endl;
    }
    return 0;
}