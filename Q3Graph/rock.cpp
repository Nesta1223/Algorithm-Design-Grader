#include <bits/stdc++.h>
using namespace std;

int dp[505][505];
int mod =  1997;

int main(){
    int n,k ; cin >> n >> k;
    for (int i=1;i<=n;i++){
        dp[i][1] = 1;
    }
    for (int i=1; i<=n;i++){//dp[n][k] = k*dp[n-1][k] + dp[n-1][k-1]
        for (int j=2;j<=i;j++){
            dp[i][j] = ((j*dp[i-1][j])%mod + dp[i-1][j-1])%mod ;
            // cout << dp[i][j] << " ";

        }
        // cout << endl;
    }
    cout << dp[n][k];
}