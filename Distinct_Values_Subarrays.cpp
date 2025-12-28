#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define printarr(arr) for(auto &x: arr) cout<<x<<" "; cout<<endl;
int main()
{
    ll n;
    cin>>n;
    vl a(n);
    rep(i,0,n)
        cin>>a[i];
    set<ll> s;
    ll l=0, r=0, ans=0;
    while(r<n){
        if(s.find(a[r]) == s.end()){
            ans+= r-l+1;
            s.insert(a[r]);
            r++;
        }
        else{
            while(s.find(a[r]) != s.end()){
                s.erase(a[l]);
                l++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}