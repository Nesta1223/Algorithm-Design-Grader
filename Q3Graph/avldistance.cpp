#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];
int visited[100005];
set<pair<int,int>> trash;

int main(){
    int n,k; cin >> n >> k;
    for (int i=1;i<= n-1;i++){
        int a,b ; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt =0;
    for (int i=1;i<=n;i++){
        memset(visited,0,sizeof visited);
        queue<pair<int,int>> q;//node,dis
        q.push({i,0});
        visited[i] = 1;
        while(!q.empty()){
            int start= q.front().first;
            int dis = q.front().second;
            q.pop();
            if (dis > k) break;
            for (auto go : g[start]){
                if (!visited[go] && !(trash.find({go,i}) != trash.end() || trash.find({i,go}) != trash.end()    )){
                    visited[go] = 1;
                    if (dis+1==k) {
                        cnt++;
                        trash.insert({i,go});
                        trash.insert({go,i});
                    }
                    q.push({go,dis+1});
                }
            }
        }

    }
    cout << cnt;
}