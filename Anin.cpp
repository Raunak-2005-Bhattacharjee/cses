#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>>vis(7,vector<ll>(7));
string st;
ll ans =0;
bool valid(ll r, ll c){
    return(r>=0  && r<7 && c>=0 && c<7);
}
void dfs(ll r, ll c, ll s){

    if(s==48 || (r == 6 && c ==0)){
         if((s==48) && (r == 6 && c==0)){
            ans++;
         }
        return;
    }

    if((!valid(r+1,c)|| vis[r+1][c]) && (!valid(r-1,c) || vis[r-1][c])) 
      { if((valid(r,c-1) && !vis[r][c-1]) && (valid(r,c+1) && !vis[r][c+1])){
        return;
    }
}
  if((!valid(r,c+1)|| vis[r][c+1]!=0) && (!valid(r,c-1) || vis[r][c-1]!=0)) 
      { if((valid(r+1,c) && !vis[r+1][c]) && (valid(r-1,c) && !vis[r-1][c])){
        return;
    }
}
 
    vis[r][c]=1;
    if(st[s]=='?' || st[s]=='L'){
        if( valid(r,c-1) && !vis[r][c-1] ){
            dfs(r,c-1,s+1);
        }
    }
    if(st[s]=='?' || st[s]=='R'){
        if( valid(r,c+1)  && !vis[r][c+1] ){
            dfs(r,c+1,s+1);
        }
    }
    if(st[s]=='?' || st[s]=='U'){
        if( valid(r-1,c) && !vis[r-1][c]){
            dfs(r-1,c,s+1);
        }
    }
    if(st[s]=='?' || st[s]=='D'){
        if(valid(r+1,c) && !vis[r+1][c] ){
            dfs(r+1,c,s+1);
        }
    }
    
    
    vis[r][c]=0;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> st;
    dfs(0,0,0);
    cout<<ans<<endl;
}