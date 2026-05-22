#include <bits/stdc++.h>
using namespace std;
int dp[1000005][5];
int mod = 100000007;
int main(){
    int n; cin >> n;
    dp[1][0] = 1;
    dp[1][1] =1;
    dp[1][2] = 1;
    for (int i=2;i<=n;i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][3] + dp[i-1][4])%mod ;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][4])%mod ;
        dp[i][2] = (dp[i-1][0] + dp[i-1][2] + dp[i-1][3])%mod ;
        dp[i][3] = (dp[i-1][2])%mod  ;
        dp[i][4] = (dp[i-1][1])%mod ;
    }


    int ans = 0;
    for (int i=0;i<=4;i++){
        ans += dp[n][i];
        ans%=mod;
    }
    cout << ans;
}