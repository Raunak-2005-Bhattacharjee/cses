#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool compare(vector<ll> a, vector<ll> b){
    if(a[0]==b[0])
        return a[1]>b[1];
    return a[0]<b[0];
}

int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>> range(n, vector<ll>(3));
    for(ll i=0; i<n; i++){
        ll a,b;
        cin>>a>>b;
        range[i][0]=a;
        range[i][1]=b;
        range[i][2]=i;
    }
    sort(range.begin(), range.end(), compare);
    vector<ll> contains(n,0), contained(n,0);
    
    ll premax=LLONG_MIN;
    for(ll i=0; i<n; i++){
        ll idx=range[i][2];
        if(premax!= LLONG_MIN && premax >= range[i][1]){
            contained[idx]=1;
        }
        premax= max(premax, range[i][1]);
    }

    ll postmin=LLONG_MAX;
    for(ll i=n-1; i>=0; i--){
        ll idx= range[i][2];
        if(postmin!= LLONG_MAX && postmin <= range[i][1]){
            contains[idx]=1;
        }
        postmin= min(postmin, range[i][1]);
    }
    for(ll i=0; i<n; i++){
        cout<<contains[i] <<" ";
    }
    cout<<endl;
    for(ll i=0; i<n; i++){
        cout<<contained[i] <<" ";
    }
    cout<<endl;
    return 0;
}