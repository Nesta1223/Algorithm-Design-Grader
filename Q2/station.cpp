#include <bits/stdc++.h>
using namespace std;

int arr[10005];
int dp[10005];
// int wachi[10005][10005];

int sentinel ( int n,int m){
    if (dp[n] != -1) return dp[n];
    if (n<= 0) return 0;
    if (n<= m+1 ) {
        dp[n] = arr[n];
        return arr[n];
    }

    int ans = INT_MAX ;
    int start = max(1,n - 2*m -1);
    for (int i= start ; i< n  ; i++){


        ans = min(ans , sentinel(i,m ));

    }
    ans += arr[n];
    dp[n] = ans;
    return ans;
}

int main(){
    int n,m ; cin >> n >> m ;
    for (int i=1 ; i<= n ; i++){
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    // dp[1] = arr[1];
    int ans = INT_MAX;
    int startans = max(1,n-m);
    for (int i= startans ; i <=n;i++){
        ans = min(ans,sentinel(i,m));
    }

    cout << ans;

    // cout << endl;
    // for (int i=1 ; i<=n ; i++) cout << dp[i] << " ";
    // cout << endl;
}