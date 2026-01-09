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
const int mod = 1e9+7;


void multiply(vvl &mat1, vvl &mat2){
    ll a= (mat1[0][0]*mat2[0][0] + mat1[0][1]*mat2[1][0])%mod;
    ll b= (mat1[0][0]*mat2[0][1] + mat1[0][1]*mat2[1][1])%mod;
    ll c= (mat1[1][0]*mat2[0][0] + mat1[1][1]*mat2[1][0])%mod;
    ll d= (mat1[1][0]*mat2[0][1] + mat1[1][1]*mat2[1][1])%mod;
    mat1[0][0]= a;
    mat1[0][1]= b;
    mat1[1][0]= c;
    mat1[1][1]= d;
}
    

void matrixpow(vvl &mat1, ll n){
    if(n==0 || n==1)
        return;
    vvl mat = {{1,1},{1,0}};
    matrixpow(mat1, n/2);
    multiply(mat1, mat1);
    if(n%2 != 0)
        multiply(mat1, mat);
}

int main()
{
    ll n;
    cin>>n;
    vvl mat1 = {{1,1},{1,0}};
    if(n==0 || n==1){
        cout<<n<<endl;
        return 0;
    }
    matrixpow(mat1, n-1);
    cout<<mat1[0][0]<<endl;
    return 0;
}