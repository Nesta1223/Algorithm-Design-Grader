#include <bits/stdc++.h>
using namespace std;

int dp[22][10005];
int arr[22];



int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n,m; cin >> n >> m;
    // printf("this is %d %d",2,3);
    for (int i=1;i<=n;i++) cin >> arr[i];
    sort(arr+1,arr+n+1);

    // for (int i=1;i<=n;i++) cout << arr[i] << " ";

    for (int i=1;i<=n;i++){
        for (int j = 1 ; j <=m ; j++){
            if (arr[i] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                if (dp[i-1][j] == 0) dp[i][j] = dp[i][j-arr[i]]+1;
                else dp[i][j] = min(dp[i][j-arr[i]]+1 ,dp[i-1][j]);
            }
        }
    }
    cout << dp[n][m];
}