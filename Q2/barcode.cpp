#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll dp[35][35][35];


int main(){
    int n,m,k ; cin >> n >> m >> k;
    dp[1][1][0] = 1LL;
    m = min(n,m);
    for (int i=2 ; i<= n; i++){

        //no change
        for (int j=2 ; j<=m; j++){
            for (int a = 0 ; a<= k;a ++){
                dp[i][j][a] = dp[i-1][j-1][a];
            }
        }
        for (int j=m+2 ; j<= 2*m; j++){
            for (int a = 0 ; a<= k;a ++){
                dp[i][j][a] = dp[i-1][j-1][a];
            }
        }
        //change
        for (int j = m+1; j<=2*m;j++){
            for (int a=0; a <= k-1; a++){
                dp[i][1][a+1] += dp[i-1][j][a];
            }
        }
        for (int j = 1; j<=m;j++){
            for (int a=0; a <= k-1; a++){
                dp[i][m+1][a+1] += dp[i-1][j][a];
            }
        }

    }
    ll ans = 0;
    for (int i=1;i<= 2*m;i++){
        ans += dp[n][i][k];
    }
    cout << ans;

}