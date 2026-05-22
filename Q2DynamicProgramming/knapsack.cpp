#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int val[1000];
int w[1000];
// set<int> ans[1000];
set<int> num;

// int knap(int a,int b){// b is remaining weight
//     if (a==0) {
//         // dp[a][b] = val[a];
//         // return dp[a][b];
//         return 0;
//     }
//     if (b==0) {
//         return 0;
//     }
//     if (w[a] > b) {
//         // num.erase(a);
//         dp[a-1][b] = knap(a-1,b);
//         dp[a][b] = dp[a-1][b];
//     }
//     else{
//         dp[a-1][b-w[a]] = knap(a-1,b-w[a]) + val[a];
//         dp[a-1][b] = knap(a-1,b);
//         if (dp[a-1][b-w[a]] > dp[a-1][b]) num.insert(a);
//         dp[a][b] = max(dp[a-1][b-w[a]],dp[a-1][b]);
//     }


//     return dp[a][b];
// }

int main(){
    int n, m;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> val[i+1];
        // num.insert(i+1);
    }
    for (int i=0;i<n;i++){
        cin >> w[i+1];
    }
    for(int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            cin >> dp[i][j];
        }
    }
    // int cnt = n;
    int a= n;
    int b = m;
    while(a!=0){
        if (b-w[a] <0){
            a--;
            continue;
        }
        if (dp[a-1][b-w[a]] + val[a] > dp[a-1][b]) {
            num.insert(a);
            b-=w[a];
        }
        // if (dp[a-1][b-w[a]] == 0 && dp[a-1][b] == 0) break;
        a--;
        if (dp[a][b] == 0) break;
    }
    cout << num.size() << endl;
    for (auto i: num) cout << i << " ";

}