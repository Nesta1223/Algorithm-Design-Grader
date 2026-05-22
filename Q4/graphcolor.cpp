#include <bits/stdc++.h>
using namespace std;

vector<int> g[55];
int color[55];
int visited[55];
unordered_map<int,int> used;

int main(){
    int n, e ; cin >> n >> e;
    for (int i=1 ;i<=e; i++){
        int a, b ; cin >> a >> b ; 
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 1;


    for (int j=0 ; j<n ; j++){//many connected component
        used.clear();
        queue<int> q;
        if (visited[j] ) continue;
        q.push(j);
        visited[j] =1;
        // used[0] = 1;
    
        // for (auto i: g[1]) cout << i << " ";
    
    
        while(!q.empty()){
            memset(color , 0 , sizeof color);
            int node = q.front();
            q.pop();
            for (auto i: g[node]){
                if (used.find(i) != used.end()){
                    color[used[i]] =1;
                    // cout << "eiei" << i << endl;
                }
            }
            int cnt = 1;
            while(true){
                if (!color[cnt]){
                    used[node] = cnt;
                    ans = max(ans,cnt);
                    break;
                }
                cnt++;
            }
            // cout << node << ' ' << cnt << endl;
            for (auto i : g[node]){
                if (used.find(i) == used.end() && !visited[i]){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }

    }
    // cout << "size" << used.size();
    cout << ans;

}