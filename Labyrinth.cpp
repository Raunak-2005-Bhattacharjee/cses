#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

ll n,m;
pair<ll,ll> start;
pair<ll,ll> ending;
vl ans;

void backtrack(vector<vector<char>> &path){
    ll x = ending.first;
    ll y = ending.second;

    while(path[x][y] != 'X'){
        char c = path[x][y];
        ans.push_back(c);

        if(c == 'U') x++;
        else if(c == 'D') x--;
        else if(c == 'L') y++;
        else if(c == 'R') y--;
    }
    reverse(ans.begin(), ans.end());
}

bool isvalid(ll x, ll y, vector<vector<char>> &grid, vector<vector<bool>> &vis){
    return (x>=0 && x<n && y>=0 && y<m && grid[x][y] != '#' && !vis[x][y]);
}

bool bfs(vector<vector<char>> &grid){
    vector<vector<char>> path(n, vector<char>(m, '*'));
    vector<vector<bool>> vis(n, vector<bool>(m));

    queue<pair<ll,ll>> q;
    q.push(start);

    path[start.first][start.second] = 'X';
    vis[start.first][start.second] = true;

    while(!q.empty()){
        ll x = q.front().first;
        ll y = q.front().second;
        q.pop();

        if(grid[x][y] == 'B'){
            backtrack(path);
            return true;
        }
        if(isvalid(x-1, y, grid, vis)){
            vis[x-1][y] = true;
            path[x-1][y] = 'U';
            q.push({x-1, y});
        }
        if(isvalid(x, y+1, grid, vis)){
            vis[x][y+1] = true;
            path[x][y+1] = 'R';
            q.push({x, y+1});
        }
        if(isvalid(x+1, y, grid, vis)){
            vis[x+1][y] = true;
            path[x+1][y] = 'D';
            q.push({x+1, y});
        }
        if(isvalid(x, y-1, grid, vis)){
            vis[x][y-1] = true;
            path[x][y-1] = 'L';
            q.push({x, y-1});
        }
    }

    return false;
}

int main(){
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin >> grid[i][j];
            if(grid[i][j]=='A') start = {i,j};
            if(grid[i][j]=='B') ending = {i,j};
        }
    }
    if(bfs(grid)){
        cout<<"YES\n"<< ans.size()<<endl;
        for(char c: ans) cout << c;
        cout<<endl;
    }
    else
        cout<<"NO\n";
    return 0;
}
