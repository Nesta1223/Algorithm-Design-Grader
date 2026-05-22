#include <bits/stdc++.h>
using namespace std;

char arr[1005][1005];
int dp[1005][1005];
int main(){
    int n,k; cin >> n >> k;
    for (int i=1 ; i<= n;i++){
        string x ;
        cin >> x;
        for (int j = 0;j<k;j++){
            arr[i][j+1] = x[j] ;
        }
        
    }

    // for (int i=1 ; i<= n; i++){
    //     for (int j= 1;j<=k ; j++) cout << arr[i][j] << " ";
    //     cout << endl;
    // }
    int ans = 0;
    for (int i=1 ; i<= n;i++){
        for (int j=1; j<= k ; j++){
            if (arr[i][j] == '1'){
                dp[i][j] = min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]}) + 1;
            }
            
            else dp[i][j] = 0;
            ans = max ( ans,dp[i][j]);
        }
    }
    cout << ans;
}