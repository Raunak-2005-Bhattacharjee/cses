#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll n;
    cin>> n;
    ll ans=0;
    for(int i= 5; i<= 1e9; i*=5){
        ans+= n/i;
    }
    cout<< ans << endl;
    return 0;
}