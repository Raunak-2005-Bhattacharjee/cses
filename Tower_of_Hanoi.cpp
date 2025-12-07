#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, int src, int dest, int aux, vector<pair<int,int>> &ans){
    if(n==1){
        ans.push_back({src, dest});
        return;
    }
    hanoi(n-1, src, aux, dest, ans);
    ans.push_back({src, dest});
    hanoi(n-1, aux, dest, src, ans);
}

int main()
{
    int n;
    cin>>n;
    int src = 1, aux = 2, dest = 3;
    vector<pair<int,int>> ans;
    hanoi(n, src, dest, aux, ans);
    cout<< ans.size()<<endl;
    for(auto a: ans){
        cout<< a.first<< " "<< a.second<<endl;
    }
    return 0;
}