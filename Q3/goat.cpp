#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[1000005][5];
ll mod = (1e9) + 7;

int main(){
    ll n,k; cin >> n >> k;
    unordered_set<int> s;
    for (int i=1;i<=k;i++) {
        int a; cin >> a;
        s.insert(a);
    }

    dp[1][1] = 1;
    if (s.find(1) == s.end()) dp[2][2] = 1;
    if (s.find(1) == s.end() && s.find(2) == s.end() && s.find(3) == s.end()) dp[4][3] =1;

    for (int i=1;i<=n;i++){
        //state1
        dp[i][1] += dp[i-1][1] + dp[i-1][2];
        //state2
        if (s.find(i-1) == s.end() && i>=2 ) {
            dp[i][2] += dp[i-2][1] + dp[i-2][3];
        }
        //state4
        if (s.find(i-1) == s.end() && s.find(i-2) == s.end() && s.find(i-3) == s.end() && i>=4){
            dp[i][3] +=dp[i-4][2] + dp[i-4][3];
        } 
        dp[i][1] %=mod;
        dp[i][2] %=mod;
        dp[i][3] %=mod;

    }
    int ans = 0;
    for (int i=1;i<=3;i++){
        ans+= dp[n][i];
        ans%= mod;
    }
    cout << ans;










}
