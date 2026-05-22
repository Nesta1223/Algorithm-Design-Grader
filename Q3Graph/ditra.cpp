#include <bits/stdc++.h>
using namespace std;


struct A{
    int node;
    int w;
    bool operator < (const A& o) const{
        return this->w > o.w;
    }
};

vector<A> g[5005];
vector<int> svec;
int dis[5005];

int main(){
    int n,m, k; cin >> n >> m >> k;
    int v; cin >> v;
    for (int i=1;i<=k;i++){
        int x ; cin >> x;
        svec.push_back(x);
    }
    for (int i=1;i<=m;i++){
        int a,b,w; cin >> a >> b >> w; 
        g[a].push_back({b,w});
        // g[b].push_back({a,w});
    }
    int ans = INT_MAX;
    for (auto start: svec){
        memset(dis,127,sizeof dis);
        priority_queue<A> pq;  
        pq.push({start,0});
        while (!pq.empty()){
            A a  = pq.top();
            pq.pop();
            for (auto i: g[a.node]){
                if (a.w +i.w < dis[i.node]){
                    dis[i.node] = a.w+i.w;
                    // cout << dis[i.node] << " ";
                    pq.push({i.node,a.w+i.w});
                }
            }
        }
        // cout << endl;
        // cout << "------" << endl;
        ans = min(ans,dis[v]);
        // cout << "------" << endl;
    }
    cout << ans;


}