#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll doublearea(int x1, int x2, int x3, int y1, int y2, int y3){
    return 1LL*(x2-x1)*(y3-y1) - 1LL*(x3-x1)*(y2-y1);
}

int main()
{
    ll area = 0;
    int n;
    cin>>n;
    vector<pair<int, int>> vertices(n);
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        vertices[i].first=a;
        vertices[i].second=b;
    }
    for(int i=2; i<n; i++){
        area+= doublearea(vertices[0].first, vertices[i-1].first, vertices[i].first, vertices[0].second, vertices[i-1].second, vertices[i].second);
    }
    cout<<abs(area)<<endl;
    return 0;
}