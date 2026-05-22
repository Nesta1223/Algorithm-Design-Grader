#include <bits/stdc++.h>
using namespace std;

int dp[305][305];
int grid[305][305];
int visited[305][305];
pair<int,int> goodd[6] = {{0,-1},{0,1} , {-1,0},{-1,1}, {1,0},{1,1}};
pair<int,int> goeven[6] = {{0,-1},{0,1} , {-1,0},{-1,-1}, {1,0},{1,-1}};

int main(){
    int r,c; cin >> r >> c;
    int a1,a2,b1,b2; cin >>a1 >> a2 >> b1 >>b2;
    for (int i=1;i<=r;i++){
        for (int j=1 ;j<=c ;j++){
            cin >> grid[i][j];

        }
    }
    memset(dp,127,sizeof dp);
    queue<pair<int,int>> q;
    dp[a1][a2] = grid[a1][a2];
    q.push({a1,a2});
    visited[a1][a2] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //maybe not
        for (int i = 0 ; i<=5;i++){
            if (x%2==1){
                int x1 = x+ goodd[i].first;
                int y1 = y + goodd[i].second;
                if (x1 <1 || y1 <1 || x1 > r || y1 >c) continue;
                if (dp[x1][y1] > dp[x][y] + grid[x1][y1]){       
                    dp[x1][y1] = min(dp[x1][y1], dp[x][y] + grid[x1][y1]);
                    q.push(make_pair(x1,y1));
                }


            }
            else if (x%2==0){
                int x1 = x+ goeven[i].first;
                int y1 = y + goeven[i].second;
                if (x1 <1 || y1 <1 || x1 > r || y1 >c) continue;
                if (dp[x1][y1] > dp[x][y] + grid[x1][y1]){       
                    dp[x1][y1] = min(dp[x1][y1], dp[x][y] + grid[x1][y1]);
                    q.push(make_pair(x1,y1));
                }

            }
        }
    }
    cout << dp[b1][b2];
}