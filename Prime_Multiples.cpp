#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n; int k;
    cin >> n >> k;
    vector<long long> primes(k);
    for(int i=0; i<k; i++)
        cin >> primes[i];
    long long ans = 0;
    for(int i=1; i<(1LL<<k); i++){
        long long temp =n;
        int count = 0;
        for(int j=0; j<k; j++){
            if(i & (1<<j)){
                temp = temp / primes[j];
                count++;
            }
        }
        ans = (count % 2 != 0) ? ans + temp : ans - temp;
    }
    cout << ans << "\n";
    return 0;
}