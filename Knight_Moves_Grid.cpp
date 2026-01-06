#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
vector<pair<ll,ll>> moves={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

bool valid(ll r, ll c){
    return (r>=0 && r<n && c>=0 && c<n);
}
void bfs(vector<vector<ll>> &ans){
    queue<pair<ll,ll>>q;
    q.push({0,0});
    ans[0][0]=0; 
    while(!q.empty()){ 
        ll r=q.front().first;
        ll c=q.front().second;
        q.pop();
        for(auto it: moves){
            ll nr= r+it.first;
            ll nc= c+it.second;
            if(valid(nr,nc) && ans[nr][nc]==-1){
                ans[nr][nc]= 1+ans[r][c];
                q.push({nr,nc});
            }
        }
    }
}
int main(){
    cin>>n; 
    vector<vector<ll>> ans(n, vector<ll>(n, -1));
    bfs(ans);
    for(ll i=0; i<n; i++){
        for(ll j=0;j<n;j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}
