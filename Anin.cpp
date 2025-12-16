#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void build( ll low, ll high, vector<ll> &seg, vector<ll> &arr, ll ind)
{
    if(low ==high)
    {
        seg[ind] = arr[high];
        return;
    }
     ll mid =(low + high)/2;
    build(low, mid, seg, arr, 2*ind+1 );
    build(mid+1, high, seg, arr,2*ind+2 );

    seg[ind] = seg[2*ind+1]+ seg[2*ind+2];
}

void point(ll low, ll high,vector<ll> &seg, ll ind, ll i , ll u)
{
    if(low == high)
    {
        seg[ind]=u;
        return;
    }
    ll mid =(low+high)/2;
    if(i<=mid){
    point(low, mid, seg, 2*ind +1 , i, u);
    }
    else{
    point(mid+1, high, seg, 2*ind +2, i ,u);
    }
    seg[ind] = seg[2*ind+1]+ seg[2*ind+2];
    }



ll query(ll low, ll high, ll l, ll h, vector<ll> &seg, ll ind )
{
    if(high<l || low>h)
    {
        return 0;
    }
    else if(low>=l && high<=h)
    {
        return seg[ind];
    }
    else{
        ll mid =(low+high)/2;
        ll left=query(low, mid, l, h, seg, 2*ind +1 );
        ll right=query(mid+1, high, l, h, seg, 2*ind +2 );
        return left + right;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  
    long long n,q;
    cin>>n>>q;
    vector<long long> arr(n);
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<ll>seg(n*4);
    build(0,n-1,seg,arr,0);
    while(q--)
    {
      ll c, k, u;
      cin>>c >> k >> u;
      if(c==1)
      {
        point(0, n-1,seg,0,k-1,u);
      }
      else if(c==2)
      {
        cout<<query(0,n-1,k-1,u-1, seg,0)<<endl;
      }


    }
}