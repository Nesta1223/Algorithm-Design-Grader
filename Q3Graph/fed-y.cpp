#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<pair<ll,ll>> g[200005];//weight, node
ll dis[200005];

int main(){
    memset(dis,127,sizeof dis);

    ll n,m ; cin >> n >> m;
    for (int i=0 ; i<m; i++){
        ll a,b,w; cin >> a >> b >> w;
        g[a].push_back({w,b});
        g[b].push_back({w,a});
    }


    dis[1] = 0;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0,1});//weight , node
    while(!pq.empty()){
        ll start = pq.top().second;
        ll prew = pq.top().first;
        pq.pop();
        for (auto i: g[start]){
            ll weight = i.first;
            ll go = i.second;
            if (dis[go] > dis[start] + weight){
                dis[go] = dis[start] + weight;
                pq.push({dis[go],go});
            }
        } 
    }
    ll maxi = 0;
    for (int i=2 ;i<=n;i++){
        maxi = max(maxi, dis[i]);
    }
    for (int i=2;i<=n;i++){
        cout << maxi-dis[i] << '\n';
    }




}