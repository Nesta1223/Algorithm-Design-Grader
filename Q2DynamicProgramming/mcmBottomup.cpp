#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int a[105];

int main(){
    int n; cin >> n;
    for (int i=1;i<=n+1;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n-1;i++){
        dp[i][i+1] = a[i] * a[i+1] * a[i+2];
    }
    for (int k = 3;k <=n;k++){
        for (int i=0;i<=n-k;i++){
            dp[1+i][k+i] = 0;
            for (int j= 1+i;j < k+i;j++){
                if (dp[1+i][k+i] ==0)   dp[1+i][k+i] = dp[1+i][ j] + dp [j+1 ][k+i] + a[1+i] *a[1+j] * a[k+i+1];
                else{
                    dp[1+i][k+i] = min( dp[1+i][k+i] , dp[1+i][ j] + dp [j+1 ][k+i] + a[1+i] * a[1+j] * a[k+i+1]);
                }
            }
        }
    }
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[1][n];
}