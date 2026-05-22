#include <bits/stdc++.h>
using namespace std;

int arr[1005];
int arr2[1005];
int dp[1005][1005];

int lis(int a,int b){
    if (dp[a][b] != -1 ) return dp[a][b];
    if (a==0 | b==0){
        dp[a][b] = 0;
        return 0;
    }
    if (arr[a] == arr2[b]) {
        dp[a][b] = lis(a-1,b-1)+1;
        return dp[a][b];
    }
    else {
        dp[a][b] =max(lis(a-1,b),lis(a,b-1));
        return dp[a][b];
    }
}
int main(){
    int n; cin >> n;
    for (int i=0;i<1005;i++){
        for (int j=0;j<1005;j++){
            dp[i][j] = -1;
        }
    }

    for (int i=1;i<=n;i++) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    sort(arr2+1,arr2+n+1);
    lis(n,n);
    cout << dp[n][n];

}