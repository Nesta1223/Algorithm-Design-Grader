#include <bits/stdc++.h>
using namespace std;

int arr[505];

int dp[505][505];


int match(int start ,int stop ){
    if (dp[start][stop] != -1) return dp[start][stop];

    if (stop - start == 1){
        dp[start][stop] = max(0 , arr[start] * arr[stop]);
        return dp[start][stop];
    }
    if (start >= stop ){
        dp[start][stop] = 0 ;
        return 0;
    }
    int adder = max(0,arr[start] * arr[stop]);
    int ans = 0;
    for (int k= start +1 ; k<= stop-1 ; k++){
        int adder2 = 0;
        if (adder ==0) adder2 = max({0,arr[start] * arr[k] , arr[k] * arr[stop]});
        ans = max({ans,match(start+1 , k-1) + match (k+1 , stop -1) + adder2});
    }
    ans += adder;
    dp[start][stop] = ans;
    return ans;


}

int main(){
    int n; cin >> n;
    for (int i=1 ;i<= n;i++) cin >> arr[i];

    for (int i=0;i<505;i++){
        for (int j=0;j<505;j++){
            dp[i][j] = -1;
        }
    }
    match (1,n);
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[1][n];


}