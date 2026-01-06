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

vector<vector<char>> grid(8, vector<char>(8));

int main()
{
    rep(i,0,8){
        rep(j,0,8){
            cin>>grid[i][j];
        }
    }
    
    return 0;
}