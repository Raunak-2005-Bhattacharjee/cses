#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll n;
    cin>> n;
    vector<ll> a(n);
    for(int i=0; i< n; i++)
        cin>> a[i];
    ll temp= 0;
    ll maxs = a[0];
    for(int i= 0; i<n; i++){
        temp+= a[i];
        maxs = max(maxs, temp);
        if(temp<0)
            temp=0;
    }
    cout<< maxs<<endl;
    return 0;
}