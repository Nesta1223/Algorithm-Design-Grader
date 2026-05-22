#include <bits/stdc++.h>
using namespace std;

int flag = 0;
vector<int> g[100005];
int ans ;
int visited[100005];


void dfs(int node,int mark,int parent){
    if (flag == 1) return;
    visited[node] = mark;
    for (auto i: g[node]){
        if (flag==1 ) break;
        if (!visited[i]){
            visited[i] = mark+1;
            dfs(i,mark+1,node);
        }
        else if (i!= parent){
            ans = visited[node] - visited[i] +1;
            flag=1;
            return;
        }
    }

}

int main(){
    int n; cin >> n;
    for (int i=1;i<=n;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // visited[0] = 1;
    dfs(0,1,-1);
    // for (int i=0;i<n;i++) cout << visited[i] << " ";
    // cout << endl;


    cout << ans ;
}