#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[1005]; //weight,node
int dis[1005][1005];

int main(){
      
    int n,m; cin >> n >> m;



    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            dis[i][j] = 1e9;
        }
    }

    for (int i=1;i<=m;i++){
        int a,b,w; cin >> a >> b >> w;
        dis[a][b] = w;
        dis[b][a] = w;
    }
    for (int i=0;i<n;i++){
        dis[i][i] = 0;
    }


    
    
    
    
    for (int k=0;k<n;k++){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
            }
        }
    }


    // for (int i=0;i<n;i++){
    //     for (int j=0;j<n;j++){
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    
    int ans = INT_MIN;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            ans = max(ans,dis[i][j]);
        }
    }
    cout << ans;


}