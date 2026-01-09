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
vl leftr(8,0), primdiag(15,0), secdiag(15,0);
ll ans=0;

void solve(ll &ans, ll col){
    if(col == 8){
        ans++;
        return;
    }
    for(ll row=0; row<8; row++){
        if(grid[row][col]=='.' && leftr[row]==0 && primdiag[row+col]==0 && secdiag[7-row+col]==0){
            leftr[row]=1;
            primdiag[row+col]=1;
            secdiag[7-row+col]=1;
            solve(ans, col+1);
            leftr[row]=0;
            primdiag[row+col]=0;
            secdiag[7-row+col]=0;
        }
    }
}

int main()
{
    rep(i,0,8){
        rep(j,0,8){
            cin>>grid[i][j];
        }
    }
    solve(ans,0);
    cout<<ans<<endl;
    return 0;
}