#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll t;
    cin>> t;
    while(t--){
        ll x1, y1, x2, y2, x3, y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        if(((x2-x1)*(y3-y1)) - ((x3-x1)*(y2-y1)) > 0)
            cout<< "LEFT" << endl;
        else if(((x2-x1)*(y3-y1)) - ((x3-x1)*(y2-y1)) < 0)
            cout<< "RIGHT" << endl;
        else
            cout<< "TOUCH" << endl;
    }
    return 0;
}