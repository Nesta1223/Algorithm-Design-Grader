#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int dp[10000005][3];
int mod = 100000007;

int main(){
    int n; cin >> n;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    for (int i=2;i<=n;i++){
        dp[i][1] = (dp[i-1][1]+dp[i-1][2] + dp[i-1][3])%mod;
        dp[i][2] = (dp[i-1][1] + dp[i-1][3])%mod;
        dp[i][3] = (dp[i-1][1] + dp[i-1][2])%mod;
    }
    int ans =0;
    for (int i=1;i<=3;i++){
        ans += dp[n][i];
        ans%= mod;
    }
    cout << ans;


    // cout << (dp[n][n][0] + dp[n][n][1] )%mod ;
}