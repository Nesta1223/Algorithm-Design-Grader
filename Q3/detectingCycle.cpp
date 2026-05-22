#include <bits/stdc++.h>
using namespace std;

int g[1005][1005];
int visited[1005];

bool dfs(int start,int v){
    visited[start] = 1;
    stack<pair<int,int>> s;
    s.push(make_pair(start,-1));
    while(!s.empty()){
        int parent = s.top().first;
        int grandparent = s.top().second;
        s.pop();
        for (int i=0;i<v;i++){
            if(g[parent][i] ){
                if (!visited[i]){
                    visited[i] = 1;
                    s.push(make_pair(i,parent));
                }
                else if (i!=grandparent){
                    return true;
                }
            }
        }  
    }
    return false;
}



bool detectCircuit(int v){
    for (int i=0;i<v;i++){
        if (visited[i] == 0){
            if ( dfs(i,v)) return true;
        }
    }
    return false;
}

int main(){
    int q ; cin >> q;
    while(q--){
        memset(g,0, sizeof g);
        memset(visited,0, sizeof visited);
        int v,e ; cin >> v >> e;//0 to v-1
        for (int i=1;i<=e;i++){
            int a, b; cin >> a >> b;
            g[a][b] = 1;
            g[b][a] = 1;
        }
        bool ans = detectCircuit(v);


        // for (int i=0;i<v;i++) cout << visited[i] << " ";


        if (ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';  
    }
}