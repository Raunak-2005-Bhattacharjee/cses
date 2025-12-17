#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll n, x;
    cin>>n>>x;
    vector<pair<ll,ll>> arr(n);
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        arr[i].first=a;
        arr[i].second=i+1;
    }
    sort(arr.begin(), arr.end());
    for(ll i=0; i<n-3; i++){
        for(ll j=i+1; j<n-2; j++){
            ll k=j+1;
            ll l=n-1;
            while(k<l){
                ll sum=arr[i].first+arr[j].first+arr[k].first+arr[l].first;
                if(sum == x){
                    cout<<arr[i].second<< " "<<arr[j].second<< " "<<arr[k].second<< " "<<arr[l].second<<endl;
                    return 0;
                }
                if(sum>x)
                    l--;
                else 
                    k++;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}