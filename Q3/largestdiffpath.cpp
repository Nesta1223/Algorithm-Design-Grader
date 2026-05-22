#include <bits/stdc++.h>
using namespace std;

int ver[2005];
vector<int> g[2005];
int visited[2005];

int dfs(int node,int parentMin){
    visited[node] = 1;
    if ( g[node].size() == 0) return ver[node] - parentMin;
    int ans = 0;
    parentMin = min( parentMin, ver[node]);
    for (auto i: g[node]){
        if (!visited[i]){
            visited[i] = 1;
            ans = max({ans, ver[i] - parentMin ,dfs(i ,parentMin)});
        }

    }
    // cout << node << " " << ans << endl;
    return ans;
}

int main(){
    int v,e ; cin >> v >> e;
    for (int i=0;i<v;i++) cin >> ver[i];
    for (int i=0;i<e;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
    }
    int ans = INT_MIN;


    for (int i=0;i< v;i++){
        memset(visited,0, sizeof visited);
        ans = max(ans , dfs(i,INT_MAX));
    }

    cout << ans;


}