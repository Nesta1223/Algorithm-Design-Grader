#include <bits/stdc++.h>
using namespace std;
int arr[200000];
int dp[200000];

int main(){
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> arr[i];
    dp[1] = arr[1];
    int nax= INT_MIN;
    for (int i=2;i<=n;i++){
        dp[i] = max(dp[i-1]+arr[i],arr[i]);
        nax = max(nax,dp[i]);
    }
    cout << nax;
}