#include <bits/stdc++.h>
using namespace std;

int g[10][10];
// int from[10];
int visited[10];


void bfs(int node,int n){
    visited[node] = 1;
    queue<int> q;
    q.push(node);
    while (!q.empty()){
        int a = q.front();
        q.pop();
        for (int i=1;i<=8;i++){
            if( visited[i] ==0 && g[a][i] ==1){
                visited[i] =1;
                q.push(i);
            }
        }
    }

    
}

int main(){
    // memset(from,-1,sizeof from);
    g[1][2] = 1;
    g[2][1] = 1;
    g[1][3] = 1;
    g[3][1] = 1;
    g[2][3] = 1;
    g[3][2] = 1;

    g[1][4] = 1;
    g[4][1] = 1;

    g[5][6] = 1;
    g[6][5] = 1;

    g[1][7] =1;
    g[7][1] = 1;
    g[1][8] = 1;
    g[8][1] = 1;

    bfs(8,8);
    for (int i=1;i<=8;i++){
        cout << i << " " << visited[i] << endl;
    }



}