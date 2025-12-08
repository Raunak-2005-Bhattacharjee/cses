#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    int n, m;
    cin>>n>>m;
    vl h(n);
    vl t(m);
    for(int i=0; i< n; i++)
        cin >> h[i];
    for(int i=0; i< m; i++)
        cin >> t[i];
    multiset<ll> s;
    for(int i=0; i< n; i++)
        s.insert(h[i]);
    for(int i=0; i<m; i++){
        if(s.empty()){
            cout<< "-1" << endl;
            continue;
        }
        auto it = s.upper_bound(t[i]);
        if(it == s.begin()){
            cout<< "-1" << endl;
        }
        else{
            --it;
            cout<< *it << endl;
            s.erase(it);
        }
    }
    return 0;
}