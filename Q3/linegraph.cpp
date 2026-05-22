#include <bits/stdc++.h>
using namespace std;

vector<int> g[200005];
int visited[200005];
int color[200005];//count the connected component

vector<int> connected[200005];

void dfs(int start,int col){
    visited[start] = 1;
    color[col] = start;
    connected[col].push_back(start);
    for (auto i: g[start]){
        if (!visited[i]){
            visited[i] =1;
            dfs(i,col);

        }
    }
}

int main(){
    int v,e; cin >> v >> e;
    memset(color,-1,sizeof color);
    for (int i=0;i<e;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int col = 1;
    for (int i=0;i<v;i++){
        if (!visited[i]){

            dfs(i,col);
            col++;
        }

    }

    // for (int i=1;i<=v;i++) cout << connected[i].size() << " ";





    int i=1;
    int ans = 0;
    while(connected[i].size() != 0){
        if (connected[i].size() == 1) {
            ans++;
            i++;
        }
        else{

            int cnt1 = 0;
            int cntx = 0;
            for (auto j : connected[i]){
                if (g[j].size() == 1) cnt1++;
                else if (g[j].size() >=3) {
                    cntx++;
                    break;
                }
            }
            if ((cnt1 == 2 && cntx ==0)  ) ans++;
            i++;
        }
    }
    cout << ans;



}