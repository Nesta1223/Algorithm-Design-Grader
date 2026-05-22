#include <bits/stdc++.h>
using namespace std;

int arr[505][505];
int dp[505][505][5];
int mod = 1e8+7;
int first[505];

int main(){
    int r,c ; cin >> r >> c;
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c;j++){
            cin >> arr[i][j];
        }
    }
    for (int i=1;i<=r;i++){
        if (arr[i][1] !=1) {
            first[i] = 1;
        }
    }
    for (int j =2 ;j<=c;j++){
        for (int i=1;i<=r;i++){
            if (arr[i][j] !=1){
                if(j==2){
                    dp[i][j][1] = first[i-1];
                    dp[i][j][2] = first[i];
                    dp[i][j][3] = first[i+1];
                    
                }
                else{
                    dp[i][j][1] = dp[i-1][j-1][2] + dp[i-1][j-1][3];
                    dp[i][j][2] = dp[i][j-1][1] + dp[i][j-1][3];
                    dp[i][j][3] = dp[i+1][j-1][1] + dp[i+1][j-1][2];
                    dp[i][j][1]%=mod;
                    dp[i][j][2]%=mod;
                    dp[i][j][3]%=mod;

                }

            }
        }
    }




    int ans = 0;
    for (int i =1;i<=r;i++){
        ans+= (dp[i][c][1] + dp[i][c][2] + dp[i][c][3] )%mod;
        ans%=mod;
    }
    cout << ans;
}   