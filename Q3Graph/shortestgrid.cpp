#include <bits/stdc++.h>
using namespace std;

int grid[105][105];
int visited[105][105];
using pi = pair<int,int>;


void bfs(pi start,int mark){
    queue<pi> q;
    queue<int> markq;
    visited[start.first][start.second] = mark;
    q.push(start);
    markq.push(mark);
    // mark++;//maybe this is wrong
    while(!q.empty()){
        pi a = q.front();
        q.pop();
        int mrk = markq.front()+1;
        markq.pop();
        //left
        if (grid[a.first- 1][a.second] ==1 && visited[a.first-1][a.second]==0   ){
            visited[a.first-1][a.second] = mrk;
            q.push(make_pair(a.first-1,a.second));
            markq.push(mrk);
        }
        //right
        if (grid[a.first+ 1][a.second] ==1 && visited[a.first+1][a.second]==0   ){
            visited[a.first+1][a.second] = mrk;
            q.push(make_pair(a.first+1,a.second));
            markq.push(mrk);
        }
        //up
        if (grid[a.first][a.second-1] ==1 && visited[a.first][a.second-1]==0 ){
            visited[a.first][a.second-1] = mrk;
            q.push(make_pair(a.first,a.second-1));
            markq.push(mrk);
        }
        //down
        if (grid[a.first][a.second+1] ==1 && visited[a.first][a.second+1]==0 ){
            visited[a.first][a.second+1] = mrk;
            q.push(make_pair(a.first,a.second+1));
            markq.push(mrk);
        }


    }
}

int main(){
    int r,c; cin >> r >> c;
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            char a ; cin >> a;
            if (a=='.') grid[i][j] = 1;
        }
    }
    bfs(make_pair(1,1),0);



    // for (int i=1;i<=r;i++){
    //     for (int j=1;j<=c;j++){
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if (visited[r][c])     cout << visited[r][c];
    else cout << -1;


}