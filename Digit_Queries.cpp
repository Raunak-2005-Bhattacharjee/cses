#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int digit(ll num , ll pos){
    string s = to_string(num);
    return s[pos] - '0';
}
int main()
{
    ll q;
    cin>>q;
    while(q--){
        ll k;
        cin>>k;
        ll grpn=9;
        ll grp=1;
        ll i =0;
        while((k-(grp*grpn)) > 0){
            k-= grp*grpn;
            grp++; grpn*=10; i++;
        }
        ll idx = (k-1)/grp;
        ll start=1;
        for (int j=0; j<i; j++) start*= 10;
        ll num = start + idx;
        ll pos = (k-1)% grp;
        ll ans = digit(num, pos);
        cout<< ans << endl;
    }
    return 0;
}