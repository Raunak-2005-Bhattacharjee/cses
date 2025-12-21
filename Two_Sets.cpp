#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll n;
    cin>>n;
    set<ll> s1, s2;
    ll sum = n*(n+1)/2;
    if(sum%2==1){
        cout<<"NO"<<endl;
        return 0;
    }
    ll halfsum=sum/2;
    for(ll i=n; i>=1; i--){
        if(halfsum>=i){
            s1.insert(i);
            halfsum-=i;
        }
        else  
            s2.insert(i);
    }
    cout<<"YES"<<endl;
    cout<<(int)s1.size()<<endl;
    for(auto it: s1)
        cout<<it<<" ";
    cout<<endl;
    cout<<(int)s2.size()<<endl;
    for(auto it: s2)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}   