#include <bits/stdc++.h>
using namespace std;

char grid[2005][2005];
int dis[2005][2005];
pair<int,int> go[4] = {{1,0} ,{-1,0} ,{0,1} ,{0,-1}};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    memset(dis, 127 ,sizeof dis);
    for (int i=0;i<2005;i++){
        for (int j=0;j<2005;j++){
            grid[i][j]= '#';
        }
    }
    int r,c; cin >> r >> c;
    pair<int,int> start;
    pair<int,int> black;
    pair<int,int> white;
    pair<int,int> stop;
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            char x; cin >> x;
            grid[i][j] = x;
            if( x=='S') start = {i,j};
            if( x=='B') black = {i,j};
            if( x=='W') white = {i,j};
            if( x=='T') stop = {i,j};
        }
    }

    // for (int i=1;i<=r;i++){
    //     for (int j=1;j<=c;j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }



    queue<pair<int,int>> q;
    queue<int> time;
    q.push(start);
    time.push(0);
    dis[start.first][start.second] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int t = time.front();
        // cout << x << " " << y << endl;
        if (q.front() == black){
            // cout << "eiei";
            dis[white.first][white.second] = t+1;
            q.push(white);
            time.push(t+1);
        }
        q.pop();
        time.pop();
        for (int i=0;i<4;i++){
            int x1= x+go[i].first;
            int y1 = y+go[i].second;
            if ( grid[x1][y1] != '#' && dis[x1][y1] > t+1){
                dis[x1][y1] = t+1;
                q.push({x1,y1});
                time.push(t+1);
            }
        }
    }



    //     for (int i=1;i<=r;i++){
    //     for (int j=1;j<=c;j++){
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (dis[stop.first][stop.second] < 2e9) cout << dis[stop.first][stop.second];
    else cout << -1;


}