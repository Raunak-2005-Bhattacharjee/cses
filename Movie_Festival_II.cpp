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

bool compare(pll a, pll b){
    return (a.first<b.first);
}

int main()
{
    ll n,k;
    cin>>n>>k;
    vector<pll> mov(n);
    rep(i,0,n)
        cin>>mov[i].first>>mov[i].second;
    sort(all(mov), compare);
    multiset<ll> st;
    rep(i,0,k)
        st.insert(mov[i].second);
    ll ans=k;
    for(ll i=k; i<n; i++){
        auto small= st.begin();
        auto large= st.rbegin();

        if(*(small) <= mov[i].first){
            ans++;
            st.erase(small);
            st.insert(mov[i].second);
        }

        else if(*(large) > mov[i].second){
            st.erase(st.find(*large));
            st.insert(mov[i].second);
        }
    }
    cout<<ans<<endl;
    return 0;
}