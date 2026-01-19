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
    ll n,m,k;
    cin>>n>>m>>k;
    vl a(n),b(m);
    inputarr(a);
    inputarr(b);
    sort(all(a));
    sort(all(b));
    ll i=0,j=0,count=0;
    while(i<n && j<m){
        if(b[j]+k < a[i]) j++;
        else if(b[j]-k > a[i]) i++;
        else{
            count++;
            i++;
            j++;
        }
    }
    cout<<count<<endl;
    return 0;
}