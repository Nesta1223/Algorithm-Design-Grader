#include <bits/stdc++.h>
using namespace std;

int g[10][10];
int from[10];
int visited[10];


void dfs(int node,int n){
    visited[node] = 1;
    for (int i=1 ; i<=n ; i++){
        if (visited[i] ==0 && g[node][i] ==1){
            visited[i] = 1;
            from[i] = node;
            dfs(i,n);
        }
    }
    
}

int main(){
    memset(from,-1,sizeof from);
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

    dfs(1,6);
    for (int i=2;i<=6;i++){
        cout << i << " " << from[i] << endl;
    }



}