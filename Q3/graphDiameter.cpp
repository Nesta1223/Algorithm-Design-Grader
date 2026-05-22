#include <bits/stdc++.h>
using namespace std;


int g[505][505];// gotonode ,weight
int dis[505][505];


int main(){
    int n,m; cin >> n >> m;
    memset(g, 63 , sizeof g);

    for (int i=1;i<=m;i++){
        int a,b,w ; cin >> a >> b >> w;
        g[a][b] = w;
    }
    for (int i=1;i<=n;i++){
        g[i][i] = 0;
        for (int j=1;j<=n;j++){
            dis[i][j] = g[i][j];
        }
    }
    for (int k=1 ;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        for (int j=1 ; j<=n;j++){
            ans = max(ans,dis[i][j]);
        }
    }
    cout << ans;

}