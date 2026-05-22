#include <bits/stdc++.h>
using namespace std;
int dp[10005][10005];
int v[10005];

int choc(int n , int k){
    if (dp[n][k] ) return dp[n][k];
    if (n==1) {
        dp[n][k] = 1;
        return 1;
    }
    int ans = 0;
    for (int i=1;i<= k;i++){
        if (n< v[k]) break;
        ans += choc(n-v[k],k) + choc(v[k],k);
        
    }
    ans = dp[n][k];
    return ans;


}

int main(){
    int n,k ; cin >> n >> k;
    for (int i=1;i<=k;i++) cin >> v[i];
    int x = choc(n,k);
    cout << x;

}