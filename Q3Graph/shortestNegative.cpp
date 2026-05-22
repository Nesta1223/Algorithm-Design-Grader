#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,pair<int,int>>;

vector<pi> edge;
int dis[105];

bool bellman(int n){
    for (int j=0 ; j<n;j++){
        for (auto i: edge){
            int node1 = i.second.first;
            int node2 = i.second.second;
            int weight = i.first;
            if (dis[node1] < 1e9 && dis[node2] > dis[node1] + weight){
                if (j==n-1) return false;
                dis[node2] = dis[node1] + weight;
            }
        }
    }
    return true;
}

int main(){
    memset(dis, 127 , sizeof dis);
    int n,e,s ; cin >> n >> e >> s;//from s to each vertex
    for (int i=1;i<=e;i++){
        pi a; cin >> a.second.first >> a.second.second >> a.first;
        edge.push_back(a);
    }
    dis[s] = 0;
    bool x = bellman(n);
    for (int i=0;i<n;i++){
        if (dis[i] > 1e9) {
            x = false;
            break;
        }
    }
    if (x){
        for (int i=0;i<n;i++){
            cout << dis[i] << ' ';
        }

    }
    else cout << -1;

}   