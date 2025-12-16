#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

bool check(ll mid, vl &a, ll k){
    ll total=0;
    for(ll i=0; i<(int)a.size(); i++){
        total += (mid/a[i]);
    }
    return total>=k;
}

int main()
{
    ll n,k;
    cin>>n>>k;
    vl a(n);
    for(ll i=0; i<n; i++)
        cin>>a[i];
    ll low=1, high=(*min_element(a.begin(), a.end()))*k, ans=0;
    while(low<=high){
        ll mid=(low+high)/2;
        if(check(mid, a, k)){
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    cout<<ans<<endl;
    return 0;   
}