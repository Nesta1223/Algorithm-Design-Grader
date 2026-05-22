#include <bits/stdc++.h>
using namespace std;


int order[1005];
int onedis[1005];
int dis[1005][1005];//เก็บทุกpath

// int walk(int a,int b , int p1 , int p2,int m){
//     int left = 0;
//     int a1 = a;
//     while(a1 != b){
//         a1--;
//         a1%=m;
//         left += onedis[a1];
//     }
//     while()

// }

int main(){
    int n , m; cin >> n >> m ;
    for (int i=0 ; i< m;i++){
        cin >> order[i];
    }
    for (int i=0;i<m;i++){
        cin >> onedis[i];
        dis[i][(i+1) %m] = onedis[i];
        dis[(i+1)%m][i] = onedis[i];
    }






    for (int i=1; i<=n;i++){//onedis[idx % m]
        int a , b; cin >> a >> b;
        int p1 = min(a,b);
        int p2 = max(a,b);
        int len = 0;
        for (int j = 0;j< m ; j++){
            int now = order[j];
            int next = order[(j+1)%m];
            int left = 
        }
    }

}