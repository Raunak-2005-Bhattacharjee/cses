#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    ll n,x;
    cin>>n>>x;
    vl a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    ll count=0;
    ll i=0,j=n-1;
    while(i<j){
        if(a[j]==x){
            j--; count++;
        }
        else if(a[i]+a[j]<=x){
            count++; i++; j--;
        }
        else{
            j--;
            count++;
        }
    }
    if(i==j) count++;
    cout<<count<<endl;
    return 0;
}