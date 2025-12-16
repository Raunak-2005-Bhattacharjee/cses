#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll n,x;
    cin>>n>>x;
    vector<pair<ll, ll>> arr(n);
    for(ll i=0; i<n; i++){
        cin>>arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(), arr.end());
    for(ll i=0; i<n-2; i++){
        ll j=i+1;;
        ll k=n-1;
        while(j<k){
            ll sum = arr[i].first+arr[j].first+arr[k].first;
            if(sum==x){
                cout<<arr[i].second<<" "<<arr[j].second<<" "<<arr[k].second<<endl;
                return 0;
            }
            else if(sum<x)
                j++;
            else
                k--;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}