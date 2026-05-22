#include <bits/stdc++.h>
using namespace std;

int dp[10005][10005];
int arr[10005];

int main(){
    int n,k; cin >> n >> k;
    for (int i=1;i<=k;i++){
        cin >> arr[i];
        dp[i][arr[i]] = 1;
    }

    for (int i=1; i<=k;i++){
        for (int j=1; j<=n;j++){
            if (j < arr[i]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                for (int x = 1;x <=i;x++){
                    if (j-arr[x] > 0)  dp[i][j] += dp[i][j-arr[x]];
                    dp[i][j] %= 1000003;
                }

            }
        }
    }

    // for (int i=1; i<=k;i++){
    //     for (int j=1; j<=n;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }



    cout << dp[k][n];
}