#include <bits/stdc++.h>
using namespace std;

struct pack{
    int start;
    int stop;
    int weight;
};
vector<int> s;
int dis[5005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m , k ; cin >> n >> m >> k;
    int v; cin >> v;
    for (int i=1;i<=k;i++){
        int a; cin >> a;
        s.push_back(a);
    }
    vector<pack> edge;
    for (int i=1;i<=m;i++){
        pack a;
        cin >> a.start >> a.stop >> a.weight;
        edge.push_back(a);
    }
    memset(dis,127 , sizeof dis);
    for (auto i : s) {
        // cout << i << endl;
        dis[i] = 0;
    }
    for (int i=1;i<=n-1;i++){
        for (auto j: edge){
            if (dis[j.start] < 2e9 && dis[j.stop] > dis[j.start] + j.weight){
                // no negative edge cycle
                dis[j.stop] = dis[j.start] + j.weight;
                // cout << j.start << " " << j.stop << endl;
                // cout << dis[j.stop] << " ";
            }
        }  
    }
    cout << dis[v];
}