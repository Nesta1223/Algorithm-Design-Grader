#include <bits/stdc++.h>
using namespace std;


struct edge{
    int weight;
    int go;
};
vector<edge> g[1005];
int visited[1005];

int minweight = 2e9;
int wuv ;
int flag = 0;

void dfs(int v , int u,int weight){
    for (auto i: g[v]){
        

        if (i.go == u){
            flag = 1;
            minweight = min(minweight , weight + i.weight+ wuv);
            return;
        }
        else if (!visited[i.go] ){
            visited[i.go] = 1;
            // cout << weight + i.weight;
            dfs( i.go , u , weight + i.weight);
        }
    }
}

int main(){
    int n , m ;cin >> n >> m;
    int c1 , c2;
    for (int i=1 ;i<= m;i++){
        int x, y ,z; cin >> x >> y >> z;
        edge e;
        e.go = y;
        e.weight = z;
        g[x].push_back(e);
        if (i==m){
            c1=x;
            c2 = y;
            wuv = z;
        }
    }
    dfs(c2, c1 , 0);
    // cout << wuv << ' ';
    if (minweight == 2e9){
        cout << "-inf" ;

    }
    else cout << wuv -minweight;

}