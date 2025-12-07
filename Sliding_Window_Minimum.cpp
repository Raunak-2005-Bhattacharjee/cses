#include<bits/stdc++.h>
using namespace std;
int findmin(vector<int> arr, int i, int j){
    int mine = 1e9;
    for(int k=i; k<=j; k++){
        mine= min(mine, arr[k]);
    }
    return mine;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        int n, k;
        cin>>n>>k;
        int x, a, b, c;
        cin>>x>>a>>b>>c;
        vector<int> arr(n);
        int ans=0;
        arr[0] = x;
        for(int i=1; i<n; i++){
            arr[i] = (1LL*a*arr[i-1] + b)%c;
        }
        deque<int> dq;
        for(int i=0; i<k; i++){
            while(!dq.empty() && arr[dq.back()] >= arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i=k; i<n; i++){
            ans ^= arr[dq.front()];
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            while(!dq.empty() && arr[dq.back()] >= arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans ^= arr[dq.front()];
        cout<<ans<<"\n";
    return 0;
}