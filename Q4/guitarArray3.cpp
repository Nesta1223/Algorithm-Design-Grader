#include <bits/stdc++.h>
using namespace std;
char grid[20][20];
int cov[20][20];
char agrid[20][20];
pair<int,int> horse[8] = {{-2,-1} , {-2,1} , {-1 ,-2} , {-1,2} , {1,-2} ,{1,2} , {2,-1} , {2,1}  };

int ans  = 2e9;

// void update (int r )


int main(){
    int n, m ; cin >> n >> m;
    int cnt = 0;
    for (int i=1 ;i<=n ; i++){
        for (int j=1 ; j<=m ; j++){
            char x ; cin >> x;
            grid[i][j] = x;
            // cov[i][j] = x;
            agrid[i][j] = x;
            if (x=='.') cnt++;
        }
    }
    // cout << cnt;
    //dont forget case #
;
    // go(1 , 1 , n,m, cnt, 0);

    // cout << ans;
    for (int i=1 ;i<=n;i++){
        for (int j=1 ; j<=m ;j++){
            cout << agrid[i][j] ;
        }
        cout << '\n';
    }

}
