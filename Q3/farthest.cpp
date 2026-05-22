#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[1005];
int dis[1005];

int main(){
    int n; cin >> n;
    for (int i=1 ;i<=n;i++){
        for (int j=1;j<=n;j++){
            int a; cin >> a;
            if (a!=-1 && i!=j) g[i].push_back({a,j});//weight,node
        }
    }
    memset(dis,127,sizeof dis);
    dis[1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;// weight,node
    pq.push({0,1});
    while(!pq.empty()){
        int start = pq.top().second;
        int prevdis = pq.top().first;
        pq.pop();
        for (auto i: g[start]){
            int go = i.second;
            int w = i.first;
            if (dis[go] > dis[start] + w){
                dis[go] = dis[start] + w;
                pq.push({dis[go],go});
            }
        }
    }
    int ans = INT_MIN;
    for (int i=1;i<=n;i++){
        ans = max(ans,dis[i]);
    }
    cout << ans;


}