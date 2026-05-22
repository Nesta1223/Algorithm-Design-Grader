#include <bits/stdc++.h>
using namespace std;

int dis[2005];
int ci[2005];
int co[2005];
vector<pair<int,int>> g[2005];//weight , goto

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    memset(dis,127 , sizeof dis);
    dis[0] = 0;
    int n, m; cin >> n >> m;
    for (int i=0;i< n;i++){
        cin >> ci[i];
    }
    for (int i=0;i<n;i++){
        cin >> co[i];
    }
    for (int i=1;i<= m;i++){
        int a,b ; cin >> a >> b;
        g[a].push_back({co[a] + ci[b],b});
    }
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        int start = pq.top().second;
        int w0 = pq.top().first;
        pq.pop();
        for (auto i: g[start]){
            int go = i.second;
            int weight = i.first;
            if (dis[go] > w0 + weight){
                dis[go] = w0 + weight ;
                pq.push({dis[go] , go});
            }
        }
    }
    for (int i= 0 ; i<n ; i++){
        if (dis[i] > 1e9) cout << -1 << " ";
        else cout << dis[i] << " ";
    }

}