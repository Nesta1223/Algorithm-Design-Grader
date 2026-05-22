#include <bits/stdc++.h>
using namespace std;

int arr[300000];
int dp[300000];
int quicksum[300000];


int main(){
    int n,w; cin >> n >> w;
    int total =0;
    for (int i=1;i<=n;i++){ 
        cin >> arr[i];
        total += arr[i];
        quicksum[i] = total;
    }
    // for (int i=1;i<=n;i++){ 
    //     cout << quicksum[i] << " ";
    // }

        dp[1] = arr[1];
    int ans = INT_MIN;
    int p=1;
    // cout << dp[1] << " ";
    for (int i=2;i<=n;i++){
        int x;
        if (i-p >=w){
            x = arr[p];
        }
        else{
            x=0;
        }

        if (dp[i-1] +arr[i] - x >= arr[i]) {
            dp[i] = dp[i-1] +arr[i] -x;
            if (x!=0) p++;
        }
        else{
            dp[i] = arr[i];
            p=i;
        }
        // cout << dp[i] << " ";
        ans = max(ans,dp[i]);
    }
    // cout << endl;
    cout << ans;
}