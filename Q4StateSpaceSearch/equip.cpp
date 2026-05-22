#include <bits/stdc++.h>
using namespace std; 

int price[10005];
int bitter[10005];
const int N = 1 << 8 + 5;
int dp[10005][N];

int main(){
    memset(dp ,127 , sizeof dp);
    int n, k; cin >> n >> k;
    for (int i=1 ; i<= n ;i++){
        cin >> price[i];
        int bit = 0;
        for (int j = 1 ; j<= k ; j++){
            int x ; cin >> x;
            if(x) bit += 1 << (j-1) ;
        }
        bitter[i] = bit;

    }
    for (int i=1 ;i<=n; i++){
        dp[i][0] = 0;
    }
    // dp[1][bitter[1]] = price[1];

    for (int i=1 ; i<=n ; i++){
        for (int j =0 ; j< 1<<k ;j++){//state
            dp[i][j | bitter[i] ] = min({dp[i][j  | bitter[i]] , dp[i-1][j] + price[i],dp[i-1][j|bitter[i]]});
        }
    }
    cout << dp[n][(1<<k)-1];


}