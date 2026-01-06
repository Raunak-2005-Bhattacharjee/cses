#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define inputarr(arr) for(auto &x: arr) cin>>x;
#define printarr(arr) for(auto &x: arr) cout<<x<<" "; cout<<endl;

class SegmentTree{
public:
    vl seg, lazy;

    SegmentTree(ll n, vl &a)
    {
        seg.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(0, 0, n - 1, a);
    }

    void build(ll ind, ll low, ll high, vl &a)
    {
        if (low == high)
        {
            seg[ind] = a[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, a);
        build(2 * ind + 2, mid + 1, high, a);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void rangeupdate(ll ind, ll l, ll h, ll low, ll high, ll val){
        if(lazy[ind]!=0){
            seg[ind]=(high-low+1)*lazy[ind];
            if(low!=high){
                lazy[2*ind+1]+=lazy[ind]; 
                lazy[2*ind+2]+=lazy[ind]; 
            }
        }
        if(h<low || l>high)
            return;
        if(low>=l && high<=h){
            seg[ind]= (high-low+1)*val;
            if(low!=high){
                lazy[2*ind+1]+=val; 
                lazy[2*ind+2]+=val; 
            }
            return;
        }
        ll mid = (low + high) / 2;
        rangeupdate(2*ind+1,l,h,low,mid,val);
        rangeupdate(2*ind+2,l,h,mid+1,high,val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    } 
};

int main()
{
    
    return 0;
}