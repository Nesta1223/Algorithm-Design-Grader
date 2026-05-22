#include <bits/stdc++.h>
using namespace std;

vector<int> g[1005];
int visited[1005];
int pre[1005];


void dfs(int node,int mark,int parent){
    visited[node] = 1;
    for(auto i: g[node]){
        if (!visited[i]){
            dfs(i,mark,node);
            pre[i] = node;
            visited[i] = 1;
        }
        else if (i!= parent){

        }
    }
}

int main(){
    int n; cin >> n;
    for (int i=0; i<n;i++){
        int m; cin >> m;
        for (int j=1;j<=m;j++){
            int a; cin >> a;
            g[i].push_back(a);
        }
    }

}