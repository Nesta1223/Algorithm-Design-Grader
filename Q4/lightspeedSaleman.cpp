#include <bits/stdc++.h>
using namespace std;


int order[1005];
int weight[1005];
int dis[1005][1005];
vector<pair<int,int>> g[1005];//weight, node

int main(){
    memset(dis, 127 , sizeof dis);
    int n, m; cin >> n >> m;
    for (int i=0;i< m ;i++){
        cin >> order[i];
    }
    for (int i=0;i<  m ;i++){
        int w; cin >> w;
        dis[i][i] = 0;
        g[i].push_back({w,(i+1)%m});
        g[(i+1)%m].push_back({w,i});
    }
    for (int i=0 ; i<m;i++){
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,i});
        while(!pq.empty()){
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            for (auto j : g[node]){
                int go = j.second;
                int w = j.first;
                if (weight + w < dis[i][go] ){
                    dis[i][go] = weight + w;
                    pq.push({dis[i][go],go});
                }
            }
        }
    }

    // for (int i=0;i<m;i++){
    //     for (int j= 0 ; j<m ; j++){
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i=1 ;i<=n ; i++){
        int p1 , p2 ; cin >> p1 >> p2;
        int sum = 0;
        for (int i=0 ; i<m ; i++){
            sum += min({dis[order[i]][order[(i+1)%m]]  , dis[order[i]][p1] + dis[p2][order[(i+1)%m]] , dis[order[i]][p2] + dis[p1][order[(i+1)%m]] } );
        }
        cout << sum << '\n';
    }


}   