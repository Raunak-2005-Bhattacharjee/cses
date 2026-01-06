#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n+1);
    unordered_map<ll,ll> p;
    p[0]=0;
    p[n+1]=n+1;
    for(ll i=1; i<=n; i++){
        cin>>a[i];
        p[a[i]] =i;
    }
    ll rnds=1;
    for(ll i=2; i<=n; i++){
        if(p[i]< p[i-1]){
            rnds++;
        }
    }

    while(m--){
        ll i, j;
        cin>>i>> j;
        if(i> j){
            swap(i, j);
        }

        ll x=a[i], y=a[j];
        if(p[x+1]>i && p[x+1] <j){
            rnds++;
        }
        if(p[x-1]> i && p[x-1] <j){
            rnds--;
        } 
        if(p[y+1]> i && p[y+1] <j){
            rnds--;
        } 
        if(p[y-1] >i && p[y-1] <j){
            rnds++;
        } 
        if(x== y+1){
            rnds--;
        }
        if(x== y-1){
            rnds++;
        }
        cout<<rnds<<endl;
        swap(a[i], a[j]);
        p[x]=j, p[y]=i;
    }

    return 0;
}