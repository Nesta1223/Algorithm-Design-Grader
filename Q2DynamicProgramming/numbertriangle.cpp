#include <bits/stdc++.h>
using namespace std;

int arr[200][200];
int dp[200][200];

int main(){
    int n; cin >> n ;
    for (int i=1;i<= n;i++){
        for (int j=1 ; j<=i;j++){
            cin >> arr[i][j];
        }
    }
    dp[1][1] = arr[1][1];
    dp[2][1] = dp[1][1]+arr[2][1];
    dp[2][2] = dp[1][1] + arr[2][2];
    for (int i=3;i<= n;i++){
        for (int j=1 ; j<=i;j++){
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + arr[i][j];
        }
    }
    int ans = INT_MIN;
    for (int i=1;i<=n;i++){
        ans = max(ans,dp[n][i]);
    }
    cout << ans;
}