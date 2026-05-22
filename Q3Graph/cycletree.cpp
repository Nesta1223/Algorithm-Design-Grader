#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];
int visited[100005];

int n;
// int flag;
void dfs(int start,int parent){
    // if(flag) return ;
    if (visited[start]){
        //cout << start << " : ";
        // flag = 1;
        cout << visited[parent] - visited[start] + 1 << '\n';
        return ;
    } 
    //cout << start << '\n';
    visited[start] = visited[parent] + 1;
    int ans = INT_MIN;
    for (auto i : g[start]){
        if(i == parent) continue; 
            dfs(i, start); 
            // cout << "yay" << endl;
        
        
    }
}

int main(){
    cin >> n;
    for (int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        a++,b++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // for (int i=0;i<n;i++){
    //     cout << i << " ";
    //     for (auto j: g[i]) cout << j << " ";
    //     cout << endl;
    // }
    dfs(1,0);
    //for(int i=1;i<=n;i++) cout << visited[i] << ' ';

    
}