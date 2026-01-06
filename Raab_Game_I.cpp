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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        if(a+b>n || ((a==0 || b==0) && (a+b != 0))){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        rep(i,1,n+1)
            cout<<i<<" ";
        cout<<endl;
        rep(i,a+1,a+b+1)
            cout<<i<<" ";
        rep(i,1,a+1)
            cout<<i<<" ";
        rep(i,a+b+1,n+1)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}