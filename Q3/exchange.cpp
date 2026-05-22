#include <bits/stdc++.h>
using namespace std;


double weight[505][505];
double dp[505][505];

int main(){
    int q; cin >> q;
    while(q--){
        // memset(weight, 127, sizeof weight);
        // memset(dp, 127, sizeof dp);
        int n; cin >> n;
        for(int i=1;i<=n;i++){
            for (int j=1; j<=n;j++){
                // cout << weight[i][j] << " ";
                cin >> weight[i][j];
                dp[i][j] = weight[i][j];
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        for (int k=1;k<=n;k++){

            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++){
                    dp[i][j] = max (dp[i][j] , dp[i][k] * dp[k][j]);
                }
            }
        }
        // for (int i=1;i<=n;i++){
        //         for (int j=1;j<=n;j++){
        //         cout << dp[i][j] << " ";
        //         }
        //         cout << endl;
        // }



        bool noo = true;
        for (int i=1;i<=n;i++){
            //  cout << dp[i][i] << " ";

            if (dp[i][i] >1){
                noo = false; 
                break;
            } 
        }


        if (noo) cout <<"NO" << '\n';
        else cout << "YES" << '\n';
    }

}