#include <bits/stdc++.h>
using namespace std;

vector<int> g[1005];
int visited[1005];
int depth[1005];
int longest = 0;

bool dfs(int start,int parent,int dep){    
    visited[start] = 1;
    depth[start] = dep;
    for (auto i: g[start]){
        if (!visited[i])   {
            bool x = dfs(i,start,dep+1);
            if (x){
                int cyclelen = depth[start] - depth[i] +1;
                longest = max(longest,cyclelen);
                return true;
            } 
        }
        else if (i!= parent) {
            int cyclelen = depth[start] - depth[i] +1;// i is ancestor
            longest = max(longest,cyclelen);
            return true;
        }
    }
    return false;
}

int main(){
    int q ; cin >> q;
    while(q--){
        // memset(visited, 0 , sizeof visited);
        // memset(g, 0 , sizeof g);
        for (int i=0;i<1005;i++) {
            g[i].clear();
            visited[i] = 0;
        }
        int v,e; cin >> v >> e;
        for (int i=1 ;i<=e;i++){
            int a,b; cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bool x = false;
        for (int i=0 ; i<v;i++){
            if (!visited[i]) x = dfs(i,-1,1);
            if (x) break;
        }
        if (x) cout << "YES"<< " " << longest << '\n';
        else cout << "NO" << '\n';

    }

}