#include <bits/stdc++.h>
using namespace std;

int dis[705];
vector<pair<int,int>> g[705];//weight,goto_node

int main(){
    //ทุกครั้งที่เริ่มปีใหม่ เริ่มทำจากปมที่ใส่เพิ่ม โดยใช้ dis[node] ของปีก่อน เพิ่มdis[node] ลง priority queue แล้วทำต่อจากเดิม ไม่ต้องทำใหม่หมด
    memset(dis,127 , sizeof dis);
    int n, big; cin >> n >> big;
    // int ans = big;
    dis[1] = 0;
    dis[2] = big;
    g[1].push_back({big,2});
    g[2].push_back({big,1});

    for (int i=3;i<=n;i++){
        int m; cin >> m;
        while(m--){
            int t,p ; cin >> t >> p;
            g[i].push_back({p,t});
            g[t].push_back({p,i});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//weight,node
        pq.push({0,1});
        while(!pq.empty()){
            int prew = pq.top().first;
            int start = pq.top().second;
            pq.pop();
            for (auto k: g[start]){
                //hard to debug
                int node = k.second;
                int weight = k.first;
                if (dis[node] > prew + weight){
                    dis[node] = prew + weight;
                    pq.push({dis[node],node});
                }
            }
        }
        cout << dis[2] << " ";
    }
}