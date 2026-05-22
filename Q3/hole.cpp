#include <bits/stdc++.h>
using namespace std;

int grid[1005][1005];
pair<int,int> go[4] ;
int visited[1005][1005];

int main(){
    go[0] = make_pair(1,0);
    go[1] = make_pair(-1,0);
    go[2] = make_pair(0,1);
    go[3] = make_pair(0,-1);
    memset(grid, -1,sizeof grid);
    int n,a,b; cin >> n >> a >> b;
    for (int i=1 ; i<=1000;i++){
        for (int j=1;j<=1000;j++){
            grid[i][j] = 0;
        }
    }

    for (int i=1;i<=n;i++){
        int x,y;
        cin >> x >> y;
        grid[x][y] = 1;
        // cout << grid[x][y];
    }
    queue<pair<int,int>> q;
    q.push(make_pair(a,b));
    visited[a][b] = 1;
    queue<int> prices;
    prices.push(0);
    int ans = INT_MAX;
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        // visited[x][y] = 1;
        int p = prices.front();
        q.pop();
        prices.pop();
        for (int i=0;i<4;i++){
            int x1 = x+ go[i].first;
            int y1 = y + go[i].second;
            if (grid[x1][y1] == -1){
                ans = min(ans,p);
                continue;
            }
            if (!visited[x1][y1]){
                // cout << grid[x1][y1];
                if (grid[x1][y1] == 1){
                    p++;
                    // cout << p << " ";
                }
                visited[x1][y1] = 1;
                q.push({x1,y1});
                prices.push(p);

            }
        }

    }
    cout << ans;
    
}