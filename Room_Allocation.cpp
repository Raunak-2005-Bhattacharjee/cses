#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int, int>> given(n);
    for(int i=0; i<n; i++)
    {
        long long a, b;
        cin>>a>>b;
        given[i] = {a, b};
    }
    vector<vector<int> > vec(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        vec[i][0] = given[i].first;
        vec[i][1] = given[i].second;
        vec[i][2] = i;
    }
    sort(vec.begin(), vec.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied;
    int roomcnt=0;
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        int arrt = vec[i][0];
        int dept = vec[i][1];
        int indx = vec[i][2];

        if(occupied.empty() || occupied.top().first >= arrt){
            roomcnt++;
            occupied.push({dept, roomcnt});
            ans[indx] = roomcnt;
        }
        else{
            int vacantroom = occupied.top().second;
            occupied.pop();
            occupied.push({dept, vacantroom});
            ans[indx] = vacantroom;
        }
    }
    cout << roomcnt << endl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}