#include <bits/stdc++.h>
using namespace std;

vector<int> g[10005];
vector<int> start;
int dis[10005];
int clk[10005];

int main(){
    memset(dis,127,sizeof dis);
    int n,m ,k; cin >> n >> m >> k;
    for (int i=1;i<=k;i++){
        int a; cin >> a;
        start.push_back(a);
    }
    for (int i=0;i<n;i++){
        cin >> clk[i];
    }
    for (int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);

    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//weight,node
    for (auto i: start) {
        dis[i] = clk[i];
        pq.push({clk[i],i});
    }
    while(!pq.empty()){
        int start = pq.top().second;
        int preweight = pq.top().first;
        pq.pop();
        for (auto i: g[start]){
            if (dis[i] > preweight + clk[i]){
                dis[i] = preweight+clk[i];
                pq.push({dis[i],i});
            }
        }
    }
    int ans = INT_MIN;
    for (int i=0;i<n;i++){
        ans = max(ans,dis[i]);
    }
    cout << ans;
    


}