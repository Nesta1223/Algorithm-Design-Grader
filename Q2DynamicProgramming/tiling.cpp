#include <bits/stdc++.h>
using namespace std;

int arr[15];
int dp[15][10005];

int main(){
    int n, m;
    cin >> n >>m ;
    for (int i=1; i<= n; i++) cin >> arr[i];
    memset(dp, 127, sizeof dp);
    dp[0][0] = 0;
    for (int i=1 ; i<= n ; i++){
        for (int j= m  ;j >= 1 ; j--){
            for (int k = 1; k<= 100;k++){
                if (j-k*k <0) break;
                dp[i][j] = min(dp[i][j] , dp[i-1][j-k*k] + (k- arr[i])*(k-arr[i]) );
            }
        }
    }
    if (dp[n][m] >=2e9) cout << -1;
    else cout <<  dp[n][m] ;

}