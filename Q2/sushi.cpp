#include <bits/stdc++.h>
using namespace std;
int arr[5005];
int dp[5005][5005];

int main(){
    int n ; cin >> n;
    for (int i=1 ; i<=n;i++) cin >> arr[i];
    for (int i=1; i<= n-1; i++) {
        dp[i][i+1] = max(arr[i],arr[i+1]);
    }
    for (int k=3; k<= n;k+=2){
        for (int i=1;i<= n;i++){
            int a = dp[i][i+k-2] + max(arr[i+k],arr[i+k-1]);
            int b = dp[i+1][i+k-1] + max(arr[i] , arr[i+k]);
            int c = dp[i+2][i+k]  + max(arr[i], arr[i+1]);
            dp[i][i+k] = max({a,b,c});
        }
    }
    cout << dp[1][n];
}
