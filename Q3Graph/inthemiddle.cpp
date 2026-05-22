#include <bits/stdc++.h>
using namespace std;

vector<int> g[250005];

int v1[250005];
int v2[250005];
int v3[250005];

int main(){
    memset(v1,127, sizeof v1);
    memset(v2,127, sizeof v2);
    memset(v3,127, sizeof v3);

    int n,s1,s2,s3 ; cin >> n >> s1 >> s2 >> s3;
    for (int i=1;i<=n;i++){
        int m; cin >> m;
        while(m--){
            int a ; cin >> a;
            g[i].push_back(a);
        }
    }
    v1[s1] = 0;
    v2[s2] = 0;
    v3[s3]  = 0;

    queue<pair<int,int>> q1;
    q1.push(make_pair(s1,0));
    while(!q1.empty()){
        int node = q1.front().first;
        int dis = q1.front().second;
        // v1[node] = dis;
        q1.pop();
        for (auto i:g[node]){
            if (v1[i] > 1e9){
                v1[i] = dis+1;
                q1.push(make_pair(i,dis+1));
            }
        }
    }

    queue<pair<int,int>> q2;
    q2.push(make_pair(s2,0));
    while(!q2.empty()){
        int node = q2.front().first;
        int dis = q2.front().second;
        // v2[node] = dis;
        q2.pop();
        for (auto i:g[node]){
            if (v2[i] > 1e9){
                v2[i] = dis+1;
                q2.push(make_pair(i,dis+1));
            }
        }
    }

    queue<pair<int,int>> q3;
    q3.push(make_pair(s3,0));
    while(!q3.empty()){
        int node = q3.front().first;
        int dis = q3.front().second;
        // v3[node] = dis;
        q3.pop();
        for (auto i:g[node]){
            if (v3[i] > 1e9){
                v3[i] = dis+1;
                q3.push(make_pair(i,dis+1));
            }
        }
    }



    int ans = INT_MAX;
    for (int i=1;i<=n;i++){
        ans = min(ans , max({v1[i],v2[i],v3[i]}));
    }
    cout << ans;

}