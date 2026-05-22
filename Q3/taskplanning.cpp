#include <bits/stdc++.h>
using namespace std;

vector<int> g[1005];
int in[1005];

int main(){
    int n; cin >> n;
    for (int i=0;i<n;i++){
        int m; cin >> m;
        for (int j=1;j<=m;j++){
            int a ; cin >> a;
            in[i]++;
            g[a].push_back(i);
        }
    }
    vector<int> order;
    queue<int> q;
    for (int i=0;i<n;i++){
        if (in[i] == 0) {
            order.push_back(i);
            q.push(i);
        }
    }
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for (auto i:g[a]){
            in[i]--;
            if (in[i] ==0){
                order.push_back(i);
                q.push(i);
            }
        }

    }
    for (auto i:order) cout << i <<" ";
}