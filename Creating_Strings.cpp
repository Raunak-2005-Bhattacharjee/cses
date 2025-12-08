#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main()
{
    string s;
    cin>>s;
    set<string> ans;
    sort(s.begin(), s.end());
    ans.insert(s);
    while(next_permutation(s.begin(), s.end())){
        ans.insert(s);
    }
    cout<< ans.size()<< endl;
    for(string temp: ans){
        cout<< temp<< endl;
    }
    return 0;
}