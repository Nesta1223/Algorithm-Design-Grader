#include <bits/stdc++.h>
using namespace std;

int grid[1005][1005];
int mingrid[1005][1005];
int maxgrid[1005][1005];
int visited[1005][1005];
pair<int,int> go[4] = {{1,0} ,{-1,0} ,{0,1} ,{0,-1}};

int main(){
    memset(grid, -1 ,sizeof grid);
    memset(mingrid,127,sizeof mingrid);
    int r,c , k ; cin >> r >> c >> k;
    vector<pair<int,int>> s;
    for (int i=1;i<=r ; i++){
        for (int j=1 ; j<=c ;j++){
            cin >> grid[i][j] ;
            if (grid[i][j] == 2) s.push_back({i,j});
        }
    }
    for (auto j : s){
        memset(visited,0 ,sizeof visited);
        queue<pair<int,int>> q;
        queue<int> time;
        q.push(j);
        time.push(0);
        mingrid[j.first][j.second] = 0;
        visited[j.first][j.second] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            int t = time.front();
            q.pop();
            time.pop();
            for (int i=0;i<4;i++){
                int x1 = x+go[i].first;
                int y1= y+go[i].second;
                if (!visited[x1][y1] && (grid[x1][y1] == 0 || grid[x1][y1] ==2)){
                    visited[x1][y1] = 1;
                    mingrid[x1][y1] = min(mingrid[x1][y1] ,t+1);
                    maxgrid[x1][y1] = max(maxgrid[x1][y1] , t+1);
                    q.push({x1,y1});
                    time.push(t+1);
                }
            }

        }    
    }
    int ans = 0;
    for (int i=1;i<=r;i++){
        for (int j=1 ;j<=c ;j++){
            // cout << mingrid[i][j] << " ";
            if (abs(maxgrid[i][j] - mingrid[i][j] <= k) && grid[i][j] !=1 && mingrid[i][j] <= maxgrid[i][j]){
                ans++;
                // cout << i << "," << j << endl;
            }
        }
        // cout << endl;
    }
    // for (int i=1;i<=r;i++){
    //     for (int j=1 ;j<=c ;j++){
    //         cout << mingrid[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    // cout << endl;




    // for (int i=1;i<=r;i++){
    //     for (int j=1 ;j<=c ;j++){
    //         cout << maxgrid[i][j] << " ";
    //     }
    //     cout << endl;
    // }   

    cout << ans;
}