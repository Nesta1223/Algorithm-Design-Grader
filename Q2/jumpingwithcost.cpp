#include <bits/stdc++.h>
using namespace std;

int arr[5005];
int cost[5005];
int dp[5005];



int main(){

    for (int i=0;i< 5005;i++)dp[i] = INT_MIN;
    int n,m ; cin >> n >> m;
    for (int i=1 ; i<= n ; i++) cin >> arr[i];
    for (int i=1 ; i<=m ; i++) cin >> cost[i];
    dp[0] = 0;
    dp[1] = arr[1];
    // cout << dp[1] << " ";
    for (int i=2 ; i<= n; i++){
        
        for (int j = 1 ; j<=m;j++){
            if (i-j == 0) break;
            // cout << dp[i-j] - cost[i-j] + arr[i] << ' ';
            dp[i] = max(dp[i],dp[i-j] - cost[j] + arr[i]);
        }
        // cout << dp[i] << " ";
    }
    // cout << endl;
    cout << dp[n];

}