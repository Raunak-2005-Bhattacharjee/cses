#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i].first;
        cin>>a[i].second;
    }
    sort(a.begin(), a.end());
    ll ans=0;
    ll tottime=0;
    for(int i=0; i<n; i++){
        tottime+= a[i].first;
        ans+= (a[i].second - tottime);
    }
    cout<<ans<<endl;
    return 0;
}