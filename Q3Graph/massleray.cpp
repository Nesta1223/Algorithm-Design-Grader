#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans[50005];
int parent[50005];

int dsu(int node){
    if (parent[node] == node) return node;
    parent[node] = dsu(parent[node]);
    return parent[node];    
}

int main(){
    int n,m,q; cin>>n>>m>>q;
    vector<pair<ll,pair<int,int>>> v;
    for (int i=1;i<=m;i++){
        int a,b,w; cin >> a >> b >> w;
        v.push_back({w,{a,b}});
        parent[i]=i;//ลืม set parent
    }
    sort(v.begin(),v.end());
    ans[n] = 0;
    int cnt = n-1;
    for (auto i: v){
        int node1 = i.second.first;
        int node2 = i.second.second;
        ll w = i.first;
        if (dsu(node1) != dsu(node2)){
            parent[dsu(node1)] = dsu(node2);
            ans[cnt] = w;
            cnt--;
        }
        if (cnt == 0) break;
    }
    while(q--){
        int x; cin >> x;
        cout << ans[x] << '\n';
    }

}