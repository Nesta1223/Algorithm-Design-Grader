#include <bits/stdc++.h>
using namespace std;

vector<int> g[5005];
vector<int> beauty;
vector<int> fire;
// int visited[5005];



int sum(vector<int> v){
    int cnt =0;
    for (auto i :v) cnt+=i;
    return cnt;
}

void dfs(int start){
    beauty[start] = 0;
    for (auto i: g[start]){
        if (beauty[i] !=0)  dfs(i); // dont dfs if not necessary
    }

}


//directed graph
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k ; cin >> n >> m >> k;
    for (int i=1;i<=n;i++) {
        int a ; cin >> a;
        beauty.push_back(a);
    }
    for (int i=1;i<=k;i++){//day of fire
        int a ; cin >> a;
        fire.push_back(a);
    }
    for (int i=1;i<=m;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
    }


    for (int i=0;i<k;i++){
        dfs(fire[i]);
        cout << sum(beauty) << ' ';
    }


}