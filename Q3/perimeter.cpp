#include <bits/stdc++.h>
using namespace std;

vector<int> g[10005];
int visited[10005];


int main(){
    int n,e,k; cin >> n >> e >> k;
    for (int i=1;i<=e;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);  
    }
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    visited[0] = -1;
    while (!q.empty()){
        int node = q.front().first;
        int dis = q.front().second;
        q.pop();
        for (auto i: g[node]){
            if (!visited[i] ){
                visited[i] = dis+1;
                q.push(make_pair(i,dis+1));
            }
        }
    }
    int cnt = 0;
    for (int i=1;i<=n;i++){
        if (visited[i] == k ) cnt++;
    }
    cout << cnt;
}