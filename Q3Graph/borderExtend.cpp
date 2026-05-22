#include <bits/stdc++.h>
using namespace std;

int grid[1005][1005];

int main(){
    pair<int,int> move[4] = {{1,0},{-1,0},{0,1},{0,-1}};
    memset(grid, -1 ,sizeof grid);
    int r,c, k ; cin >> r >> c >> k;
    queue<pair<int,int>> q;
    queue<int> time;
    for (int i=1;i<=r ; i++){
        for (int j=1;j<=c ; j++){
            cin >> grid[i][j] ; 
            if (grid[i][j]){
                q.push(make_pair(i,j));
                time.push(k);
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int t = time.front();
        // cout << t << endl;
        if (t<=0) break; 
        q.pop();
        time.pop();
        for (int i=0;i<=3;i++){

            int x1 = x+move[i].first;
            int y1 = y+move[i].second;
            if (grid[x1][y1] == 0){
                // cout << x1 << "," << y1 << endl;
                grid[x1][y1] = 2;
                q.push(make_pair(x1,y1));
                time.push(t-1);
            }
        }

    }
    for (int i=1;i<=r ; i++){
        for (int j=1;j<=c ; j++){
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }


    

}