#include<bits/stdc++.h>
using namespace std;

vector<int> g[100100];
vector<pair<int,int>> g2;
int path[2020][2002];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        g2.push_back({u,v});
    }
    return 0;
}