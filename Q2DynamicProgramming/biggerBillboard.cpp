#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll arr[1000005];
ll dp[1000005];

int main(){
    ll n; cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> arr[i];
    } 
    dp[1] = arr[1];
    dp[2] = arr[2] ;
    dp[3] = arr[3];
    for (ll i=4;i<=n;i++){
        dp[i] = max({dp[i-3],dp[i-4],dp[i-5]}) + arr[i];
    }
    cout << max({dp[n],dp[n-1],dp[n-2]});
}