#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
        ll t;
        cin >> t;
        while(t--){
            ll x, y;
            cin >> x >> y;
            ll ans=0;
            if(y>=x){
                if(y%2==1){
                    ans = (y*y)-(x-1);
                }
                else{
                    ans= (y-1)*(y-1)+1 +(x-1);
                }
            }
            else{
                if(x%2==0){
                    ans = (x*x)-(y-1);
                }
                else{
                    ans= ((x-1)*(x-1))+1+(y-1);
                }

            }
            cout<<ans<<endl;
        }
    }