#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define printarr(arr) for(auto &x: arr) cout<<x<<" "; cout<<endl;
int main()
{
    ll n,k;
    cin>>n>>k;
    vl a(n);
    rep(i,0,n)
        cin>>a[i];
    unordered_map<ll,ll> mp;
    ll l=0, r=0, ans=0;
    while(r<n){
        mp[a[r]]++;
        if(mp.size()<=k){
            ans+= r-l+1;
            r++;
        }
        else{
            while(mp.size()> k){
                mp[a[l]]--;
                if(mp[a[l]] == 0)
                    mp.erase(a[l]);
                l++;
            }
            ans+= r-l+1;
            r++;
        }
    }
    cout<<ans<<endl;
    return 0;
}