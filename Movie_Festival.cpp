#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

bool compare(pair<ll,ll> a, pair<ll,ll> b){
    if(a.second<b.second)
        return true;
    else if(a.second==b.second)
        return (a.first<b.first);
    return false;
}

int main()
{
    ll n;
    cin>>n;
    vector<pair<ll,ll>> movies(n);
    for(ll i=0; i<n; i++)
        cin>>movies[i].first>>movies[i].second;
    sort(movies.begin(), movies.end(), compare);
    ll currend=movies[0].second;
    ll ans=1;
    ll i=1;
    while(i<n){
        if(movies[i].first>=currend){
            currend=movies[i].second;
            ans++;
        }
        i++;        
    }
    cout<<ans<<endl;
    return 0;
}