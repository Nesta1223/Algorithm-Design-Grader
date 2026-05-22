#include <bits/stdc++.h>
using namespace std;

int dp[5005][5005];
int mod = 100000007;

int main(){
    int n,k; cin >> n >> k;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i=2; i<=n ; i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][k])%mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][k])%mod;
        for (int j=2; j<=k;j++){
            if (j> i) break;
            dp[i][j] = dp[i-1][j-1];
        }
    }
    int ans = 0;
    for (int i=0;i<=k;i++) {
        ans += dp[n][i];
        ans %=mod;
    }
    cout << ans;
}