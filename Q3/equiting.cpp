#include <bits/stdc++.h>
using namespace std;


int grid[1005][1005];
int visited[1005][1005];
int mingrid[1005][1005];
int maxgrid[1005][1005];
pair<int,int> go[4] = {{1,0},{-1,0},{0,1},{0,-1}};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    memset(grid, -1 , sizeof grid);
    memset(mingrid, 127 ,sizeof mingrid);
    int r,c ; cin >> r >> c;
    vector<pair<int,int>> v;
    for (int i=1;i<=r ; i++){
        for (int j=1;j<=c ; j++){
            cin >> grid[i][j];
            if (grid[i][j] ==   2){
                v.push_back({i,j});
            }
        }
    }
    for (int k=0;k<v.size();k++){
        memset(visited,127 ,sizeof visited);
        queue<pair<int,int>> q;
        queue<int> time;
        q.push(v[k]);
        time.push(0);
        visited[v[k].first][v[k].second] = 0;
        mingrid[v[k].first][v[k].second] = 0;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            int t = time.front();
            q.pop();
            time.pop();
            for (int i=0; i< 4;i++){
                int x1 = x+go[i].first;
                int y1 = y+go[i].second;
                if (visited[x1][y1] > t+1 && (grid[x1][y1]==0 || grid[x1][y1] == 2)){
                    // cout << "eiei";
                    visited[x1][y1] = t+1;
                    mingrid[x1][y1] = min(mingrid[x1][y1] , t+1);
                    maxgrid[x1][y1] = max(maxgrid[x1][y1] ,t+1);
                    q.push({x1,y1});
                    time.push(t+1);
                }
            }
        }

    }

    // for (int i=1;i<=r;i++){
    //     for (int j=1;j<=c;j++){
    //         cout << maxgrid[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int k=0;k<v.size();k++){
    //     cout << "plane" << k << endl;
    //     for (int i=1;i<=r;i++){
    //         for (int j=1;j<=c;j++){
    //             cout << visited[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    // }





    int ans = 0;
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            if ( grid[i][j] == 0 &&abs(maxgrid[i][j] - mingrid[i][j]) <=1) ans++;
        }
    }
    cout << ans;




}