#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)x.size()
#define ll long long 
#define all(x) begin(x),end(x)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        u--,v--;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }

    vector<int> ans(n),vis(n);
    auto dfs = [&](auto &self,int u,int p) ->void{
        vis[u] = 1;
        for(auto [v,i]:adj[u]){
            if(v == p) continue;
            if(vis[v]){
                ans[i] = 1;
                continue;
            }
            ans[i] = 0;
            self(self,v,u);
        }
    };

    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        dfs(dfs,i,-1);
    }

    for(auto e:ans) cout << e << ' ';
    return 0;
}