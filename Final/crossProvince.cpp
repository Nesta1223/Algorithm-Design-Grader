#include <bits/stdc++.h>
using namespace std;

// int w[3000][3000];
int dis1[100005];
int dis2[100005];


vector<pair<int,int>> g1[100005];
vector<pair<int,int>> g2[100005];//weight, node

int main(){
    // memset(w,127 , sizeof w);
    // memset(dis, 127 , sizeof dis);
    int n, m , q ; cin >> n >> m >> q;
    int bign = 2*n-1;

    for (int i=1 ; i<=n;i++) {
        dis1[i] = 1e9;
        dis2[i] = 1e9;
    }


    for (int i=1 ;i<=m;i++){
        int x,y,z ; cin >> x >> y >>z;
        if (x < n || y < n ){
            g1[x].push_back({z,y});
            g1[y].push_back({z,x});
        }
        else{
            x = x-n; 
            y = y-n;
            g2[x].push_back({z,y});
            g2[y].push_back({z,x});
        }

    }

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq1;
    //start at n;
    pq1.push({0,n});
    dis1[n] = 0;
    while(!pq1.empty()){
        int start = pq1.top().second;
        int w = pq1.top().first;
        pq1.pop();
        for (auto i : g1[start]){
            if (dis1[i.second] > dis1[start] + i.first){
                dis1[i.second] = dis1[start] + i.first;
                pq1.push({dis1[i.second] , i.second});
            }
        }

    }
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq2;
    pq2.push({0,0});
    dis2[0] = 0;
    while(!pq2.empty()){
        int start = pq2.top().second;
        int w = pq2.top().first;
        pq2.pop();
        for (auto i : g2[start]){
            if (dis2[i.second] > dis2[start] + i.first){
                dis2[i.second] = dis2[start] + i.first;
                pq2.push({dis2[i.second] , i.second});
            }
        }
        
    }

    for (int i=1 ; i<=q ; i++){
        int a ,b; cin >> a >> b;
        cout << dis1[a] + dis2[b-n] << '\n';
    }



}