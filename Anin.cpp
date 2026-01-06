#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
        ll n, k;
        cin >> n >> k;
        vector<pair<ll,ll>>v(n);
        for(ll i=0; i<n; i++){
            cin>>v[i].first>>v[i].second;
        }
        sort(v.begin(),v.end());
        multiset<ll>et;
        for(ll i=0; i<k; i++){
            et.insert(v[i].second);

        }
        ll cnt=k;
        for(ll i=k; i<n; i++){
            auto max = et.rbegin();
            auto min = et.begin();
            if(v[i].first>=*(min)){
                cnt++;
                et.insert(v[i].second);
                et.erase(min);

            }
            else if(v[i].second< *(max)){
                et.erase(et.find(*max));
                et.insert(v[i].second);
            }
        }

        cout<<cnt;
    }