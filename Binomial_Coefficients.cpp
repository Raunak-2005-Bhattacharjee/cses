#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
const int SIZE = 1e6;
const int MOD = 1e9+7;
vl fact(SIZE+1);
void factorial(){
    fact[0]=1;
    for(int i=1; i<= SIZE; i++){
        fact[i] = fact[i-1]*i%MOD;
    }
}
int main()
{
    ll n;
    cin>>n;
    factorial();
    while(n--){
        ll a, b;
        cin>>a>>b;
        ll res= (((fact[a]/fact[b])%MOD)/fact[a-b])%MOD;
        cout<< res << endl;
    }
    return 0;
}