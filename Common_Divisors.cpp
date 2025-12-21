#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
const ll SIZE = 1e6;
int main()
{
    ll n;
    cin>>n;
    vl a(n);
    vl freq(SIZE+1);
    for(ll i=0; i<n; i++){
        cin>>a[i];
        freq[a[i]]++;
    }
    for(ll i=SIZE; i>=1; i--){
        ll count=0;
        for(ll j=i; j<=SIZE; j+=i){
            count+= freq[j];
        }
        if(count>=2){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}