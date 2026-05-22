#include <bits/stdc++.h>
using namespace std;

int arr[505][505];
int dp[505][505];

int main(){
    int n,m ; cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j = 1; j<=m;j++){
            cin >> arr[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j = 1; j<=m;j++){
            if (i!=1 && j!=1)
            dp[i][j] = max({dp[i-1][j] +arr[i][j] ,dp[i][j-1]+arr[i][j] , dp[i-1][j-1] + 2*arr[i][j]});
            else
            dp[i][j] = max({dp[i-1][j] +arr[i][j] ,dp[i][j-1]+arr[i][j] });
        }
    }
    cout << dp[n][m];   
}