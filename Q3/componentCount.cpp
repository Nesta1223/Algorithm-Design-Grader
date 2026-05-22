#include <bits/stdc++.h>
using namespace std;

int g[10005][10005];
int visited[10005];


void dfs(int start,int color,int n){
    stack<int> s;
    s.push(start);
    visited[start] = color;
    while(!s.empty()){
        int parent = s.top();
        s.pop();
        for (int i=1 ; i<= n;i++){
            if (visited[i] ==0 && g[parent][i]){
                visited[i] = color;
                s.push(i);
            }
        }
    }

}


int findConnect(int n){
    int color = 0;
    for (int i=1;i<=n;i++){
        if (visited[i] == 0) {
            color++;
            dfs(i,color,n);
        }
    }
    return color;
}




int main(){
    int v,e; cin >> v >> e;
    for (int i=0;i<e;i++){
        int a, b; cin >> a >> b;
        g[b][a] = 1;
        g[a][b] = 1;
    }
    int x = findConnect(v);
    // for (int i=1;i<=v;i++) cout << visited[i] << " ";
    // cout << endl;


    cout << x;
}