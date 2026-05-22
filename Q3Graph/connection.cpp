#include <bits/stdc++.h>
using namespace std;

vector<int> g[1005];
int visited[1005];


void bfs(int start,int k){
    if (k==0) return ;
    visited[start] = 1;
    queue<pair<int,int>> q;
    q.push(make_pair(start,k));
    while (!q.empty() ){
        int a = q.front().first;
        int k2 = q.front().second;
        if (k2 ==0) break;
        q.pop();
        for (auto i : g[a]){
            visited[i] = 1;
            q.push(make_pair(i,k2-1));
        }
    }
}

int main(){
    int n,e,k ; cin >> n >> e >> k;
    for (int i=1;i<=e ; i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);  
    }
    int ans = 0;
    for (int i=0 ; i<n; i++){
        memset(visited,0,sizeof visited);
        bfs(i,k);
        int x  = 0;
        for (int i=0 ; i<n ; i++){
            x+= visited[i];
            // if (i== 5) cout << visited[i] << " ";
        }
        // cout << x << " ";
        ans = max(ans, x);  
    }
    cout << ans;

}