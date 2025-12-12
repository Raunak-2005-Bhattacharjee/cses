#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll n;
    cin>>n;
    vl t(n);
    for(int i=0; i<n; i++)
        cin>>t[i];
    sort(t.begin(), t.end());
    ll sum = accumulate(t.begin(), t.end(), 0ll);
    ll greatest = t[n-1];
    ll remsum = sum- greatest;
    ll ans;
    if(greatest > remsum){
        ans = 2*greatest;
    }
    else{
        ans = sum;
    }
    cout<< ans << endl;
    return 0;
}