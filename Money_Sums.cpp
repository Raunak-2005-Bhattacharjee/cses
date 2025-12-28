#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define printarr(arr) for(auto &x: arr) cout<<x<<" "; cout<<endl;

void f(ll i, ll sum, ll n, vl &a, set<ll> &s){
    if(i==n){
        s.insert(sum);
        return ;
    }
    f(i+1, sum+a[i], n, a, s);
    f(i+1, sum, n, a, s);
}

int main()
{
    ll n;
    cin>>n;
    vl a(n);
    rep(i,0,n)
        cin>>a[i];
    set<ll> ans={0};
    // f(0, 0, n, a, s);
    for(ll x: a){
        set<ll> temp=ans;
        for(ll s: ans){
            temp.insert(x+s);
        }
        ans=temp;
    }
    ans.erase(0);
    cout<<ans.size()<<endl;
    for(auto it: ans)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}