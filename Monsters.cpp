#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define printarr(arr) for(auto &x: arr) cout<<x<<" "; cout<<endl;

ll n,m;
vector<vector<char>> grid;
vvl dir;
vvl distp, distm;
ll closestr, closestc, closestdist=LLONG_MAX;
ll pr, pc;
vector<char> ans;

void addends(vector<pll> &ends){
    rep(i,0,m)
        if(grid[0][i] == '.')
            ends.push_back({0,i});
    rep(i,0,m)
        if(grid[n-1][i] == '.')
            ends.push_back({n-1,i});
    rep(i,0,n)
        if(grid[i][0] == '.')
            ends.push_back({i,0});
    rep(i,0,n)
        if(grid[i][m-1] == '.')
            ends.push_back({i,m-1});
}

bool checknext(ll i, ll j){
    return (i>=0 && i<n && j>=0 && j<m && grid[i][j]!='#');
}

void bfs(vvl &dist, queue<pll> &q){
    while(!q.empty()){
        ll r= q.front().first;
        ll c = q.front().second;
        q.pop();
        vl dr={-1,0,1,0};
        vl dc={0,1,0,-1};
        for(ll i=0; i<4; i++){
            ll newr=r+dr[i];
            ll newc=c+dc[i];
            if(checknext(newr,newc) && dist[newr][newc] > dist[r][c]+1){
                dist[newr][newc] = dist[r][c]+1;
                q.push({newr,newc});
                dir[newr][newc]=i;
            }
        }
    }
}

void path(){
    ll r=closestr, c=closestc;
    string helper= "URDL";
    while(r!= pr || c!=pc){
        ans.push_back(helper[dir[r][c]]);
        if(dir[r][c] == 0) r+=1;
        else if(dir[r][c] == 1) c-=1;
        else if(dir[r][c] == 2) r-=1;
        else c+=1;
    }
    reverse(all(ans));
}

int main()
{
    cin>>n>>m;
    grid.resize(n,vector<char>(m));
    distp.resize(n,vl(m, LLONG_MAX));
    distm.resize(n,vl(m, LLONG_MAX));
    dir.resize(n,vl(m));
    queue<pll> mons;
    queue<pll> per;
    bool cornerA=false;
    rep(i,0,n){
        rep(j,0,m){
            cin>>grid[i][j];
            if(grid[i][j] == 'A'){
                distp[i][j]=0;
                pr=i;
                pc=j;
                if(i==0 || j==0 || i==n-1 || j==m-1)
                    cornerA=true;
            }
            else if(grid[i][j] == 'M'){
                distm[i][j]=0;
                mons.push({i,j});
            }
        }
    }
    per.push({pr,pc});
    bfs(distm, mons);
    bfs(distp, per);
    vector<pll> ends;
    addends(ends);
    for(auto it: ends){
        auto [r,c] = it;
        if(distm[r][c] > distp[r][c] && closestdist>distp[r][c]){
            closestdist=distp[r][c];
            closestr=r;
            closestc=c;
        }
    }
    if(cornerA){
        cout<<"YES"<<endl<<"0"<<endl;
        return 0;
    }
    if(closestdist==LLONG_MAX){
        cout<<"NO"<<endl;
        return 0;
    }
    path();
    cout<<"YES"<<endl<<ans.size()<<endl;;
    for(auto it: ans)
        cout<<it;
    cout<<endl;
    return 0;
}