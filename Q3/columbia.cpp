#include <bits/stdc++.h>
using namespace std;

pair<int,int> go[4] = {{1,0},{-1,0},{0,1},{0,-1}};

int main(){
    int r,c ; cin >> r >> c;
    int grid[r+5][c+5];
    int dp[r+5][c+5];
    memset(dp,127, sizeof dp);
    memset(grid,127, sizeof grid);
    for (int i=1;i<=r;i++){
        for (int j=1 ;j<=c ;j++){
            cin >> grid[i][j];
        }
    }
    dp[1][1] = 0;
    queue<pair<int,int>> q;
    queue<int> price;
    price.push(0);
    q.push({1,1});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        // int p = price.front();
        q.pop();
        // price.pop();
        for (int i=0; i<=3;i++){
            int x1 = x + go[i].first;
            int y1 = y+ go[i].second;
            if (dp[x1][y1] > dp[x][y] + grid[x1][y1]){
                dp[x1][y1] = dp[x][y] + grid[x1][y1];
                q.push({x1,y1});
                // price.push(dp[x1][y1]);
            }
        }
    }
    for (int i=1;i<=r;i++){
        for (int j=1 ;j<=c ;j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
}