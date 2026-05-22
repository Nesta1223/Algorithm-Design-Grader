#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll parent[2005];
vector<pair<ll,pair<ll,ll>>> order;
ll arr[2005];
int used[2005];

ll dsu(ll node){
    if (parent[node] == node) return node;
    parent[node] = dsu(parent[node]);
    return parent[node];
}

int main(){
    ll n ; cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> arr[i];
        parent[i] = i;
    }
    // for (int i=1;i<=n;i++){
    //     cout << parent[i] << " ";
    // }
    for (int i=1;i<=n;i++){
        for (int j = i+1;j<=n;j++){
            int x = arr[i];
            int y  = arr[j];
            order.push_back({x^y,{i,j}});//keep index
        }
    }
    sort(order.begin(),order.end(),greater<pair<ll,pair<ll,ll>>>());
    ll ans =0;
    for (auto i: order){
        int p = i.first;
        int n1 = i.second.first;
        int n2 = i.second.second;
        if(dsu(n1) != dsu(n2)){
            // cout << arr[n1] << " " << arr[n2] << endl;
            parent[dsu(n1)] = dsu(n2);
            // cout << dsu(n1) << " " << dsu(n2) << endl;
            ans+=p;
        }
    }
    // for (int i=1;i<=n;i++){
    //     cout << parent[i] << " ";
    // }
    cout << ans;
}