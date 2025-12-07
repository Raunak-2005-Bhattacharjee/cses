#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isvalid(vector<ll> &a, ll n, ll k, ll mid){
    ll currsum = 0, part = 1;
    for(ll i = 0; i < n; i++){
        if(currsum + a[i] <= mid){
            currsum += a[i];
        }
        else{
            part++;
            currsum = a[i];
            if(part > k)
                return false;
        }
    }
    return true;
}
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++)
        cin >> a[i];
    ll low = *max_element(a.begin(), a.end());
    ll high = accumulate(a.begin(), a.end(), 0LL);
    ll ans = 0;
    while(low <= high){
        ll mid = (low+high)/2;
        if(isvalid(a, n, k, mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}