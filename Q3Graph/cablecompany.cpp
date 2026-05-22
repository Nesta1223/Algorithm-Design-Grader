#include <bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int>>> price;
int visited[1005];
int parent[1005];

int dsu(int node){
    if (parent[node] == node) return node;
    parent[node] = dsu(parent[node]);
    return parent[node];
}

int main(){
    int n; cin >> n;
    for (int i=0;i<n-1;i++){
        for (int j= i+1; j<= n-1;j++){
            pair<int,int> p1 = make_pair(i,j);
            int a ; cin >> a;
            price.push_back(make_pair(a,p1));
        }
    }
    for (int i=0;i<n;i++){
        parent[i] = i;
    }



    sort(price.begin(),price.end());
    int ans = 0;
    for (auto i: price){

        int pri = i.first;
        int node1 = i.second.first;
        int node2 = i.second.second;
        // cout << pri << " " << node1 << ":" << node2 << endl;

        if (dsu(node1) != dsu(node2)){
            ans += pri;
            parent[dsu(node1)] = dsu(node2);

        }
    }


    // cout << endl;
    cout << ans;

}