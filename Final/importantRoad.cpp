#include <bits/stdc++.h>
using namespace std;


struct road{
    int must;
    int weight;
    int node1;
    int node2;
    bool operator< (const road &r) const{
        if (this->must == r.must){
            return this->weight < r.weight;
        }
        return this->must > r.must;
    }
}; 

int parent[100005];


int dsu(int node){
    if (parent[node] == node) return node;
    parent[node]  = dsu(parent[node]);

    return parent[node];
}

int main(){
    int n,m , k; cin >> n >>m >> k;

    vector<road> v;
    for (int i=1 ; i<= k ;i++){
        road r ;
        r.must = 1;
        cin >> r.node1 >> r.node2 >> r.weight;
        v.push_back(r);
    }

    for (int i=1; i<=n;i++) parent[i] = i;
    for (int i=k+1 ; i<= m ;i++){
        road r ;
        r.must = 0;
        cin >> r.node1 >> r.node2 >> r.weight;
        v.push_back(r);
    }


    
    sort(v.begin() , v.end());


    // for (auto roll : v){
    //     cout << roll.must<< " ";
    // }
    int ans = 0;
    for (auto roll : v){
        if (roll.must == 1){
            parent[dsu(roll.node1)] = dsu(roll.node2);
            ans += roll.weight;
        }
        else{
            if (dsu(roll.node1) != dsu(roll.node2)){
                parent[dsu(roll.node1)] = dsu(roll.node2);
                ans += roll.weight;
            }
        }
    }
    cout << ans;

}