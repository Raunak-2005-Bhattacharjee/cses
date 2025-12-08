#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    int n;
    cin>>n;
    ll x;
    cin >> x;
    vl a(n);
    for(int i=0; i<n; i++)
        cin>> a[i];
    ll count = 0;
    map<ll, ll> presum;
    presum[0] = 1;
    ll pref=0;
    for (int i=0; i< n; ++i) {
        pref+= a[i];
        count+= (presum[pref-x]);
        presum[pref]+= 1;
    }
    cout<< count << endl;
    return 0;
}