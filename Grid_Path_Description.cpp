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

vvl vis(7, vl(7));
ll ans=0;

bool valid(ll x, ll y){
    return (x>=0 && x<7 && y>=0 && y<7);
}

void f(ll x, ll y, ll step, string &s){
    if(step== 48 || (x==6 && y==0)){
        if(step== 48 && (x==6 && y==0))
            ans++;
        return;
    }
    
    if((!valid(x-1,y) || vis[x-1][y]) && (!valid(x+1,y) || vis[x+1][y])){
        if((valid(x,y-1) && !vis[x][y-1]) && (valid(x,y+1) && !vis[x][y+1])){
            return;
        }
    }
    if((!valid(x,y-1) || vis[x][y-1]) && (!valid(x,y+1) || vis[x][y+1])){
        if((valid(x-1,y) && !vis[x-1][y]) && (valid(x+1,y) && !vis[x+1][y])){
            return;
        }
    }
    vis[x][y]=1;
    if(s[step]=='?' || s[step]=='L'){
        if(valid(x,y-1) && !vis[x][y-1])
            f(x,y-1,step+1,s);
    }
    if(s[step]=='?' || s[step]=='R'){
        if(valid(x,y+1) && !vis[x][y+1])
            f(x,y+1,step+1,s);
    }
    if(s[step]=='?' || s[step]=='U'){
        if(valid(x-1,y) && !vis[x-1][y])
            f(x-1,y,step+1,s);
    }
    if(s[step]=='?' || s[step]=='D'){
        if(valid(x+1,y) && !vis[x+1][y])
            f(x+1,y,step+1,s);
    }
    vis[x][y]=0;
}

int main()
{
    string s;
    cin>>s;
    f(0,0,0,s);
    cout<<ans<<endl;
    return 0;
}