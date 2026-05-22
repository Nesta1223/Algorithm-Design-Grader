#include <bits/stdc++.h>
using namespace std;

int a[105];
int dp[105][105];

int mcm(int l,int r){
    if (l < r) {
        if (dp[l][r] == -1){
            int minCost = INT_MAX;
            for (int i=l;i<r;i++){
                int myCost = mcm(l,i) + mcm(i+1,r) + (a[l] * a[i+1] * a[r+1]);
                minCost = min(myCost,minCost);
            }
            dp[l][r] = minCost;
            return minCost;
        }
        else return dp[l][r];
    }
    else{
        return 0;
    }
}

int main(){
    int n; cin >> n;
    for (int i=1;i<=n+1;i++){
        cin >> a[i];
    }
    for (int i=0;i<105;i++){
        for (int j=0;j<105;j++){
            dp[i][j] = -1;
        }
    }

    int x = mcm(1,n);
    cout << x;
}