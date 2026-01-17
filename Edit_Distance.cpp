#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define inputarr(arr) for(auto &x: arr) cin>>x;
#define printarr(arr) for(auto &x: arr) cout<<x<<" "; cout<<endl;
int main()
{
    string s,t;
    cin>>s>>t;
    ll n=s.length();
    ll m=t.length();
    vl prev(m+1,0);
    vl cur(m+1,0);
    rep(i,0,m+1)
        prev[i]=i;
    for(ll i=1; i<=n;i++){
        cur[0]=i;
        for(ll j=1;j<=m;j++){
            if (s[i-1]==t[j-1]){
                cur[j]= prev[j-1];
            } 
            else{
                cur[j]= 1+min(prev[j-1], min(prev[j],cur[j-1]));
            }
        }
        prev= cur;
    }
    cout<<cur[m]<<endl;
    return 0;
}