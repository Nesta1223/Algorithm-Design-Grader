#include <bits/stdc++.h>
using namespace std;
using ll = long long ;



short hadaa[(1<<15) +1][(1<<15) +1];


short hada(ll n, ll row , ll col){
    if (n==1) {
        hadaa[row][col] = 1;
        return 1;
    }
    if (row > n/2 && col >n/2 ) {
        short x = -hada(n/2,row-n/2,col-n/2);
        hadaa[row][col] = x;
        return x;
    }
    else if (row <= n/2 && col >n/2 ){
        short x = hada(n/2,row,col-n/2);
        hadaa[row][col] = x;
        return x;
     }
    else if (row > n/2 && col <=n/2 ) {
        short x =hada(n/2,row-n/2,col);
        hadaa[row][col] = x;
        return x;
    }
    else  {
        short x = hada(n/2,row,col);
        hadaa[row][col] = x;
        return x;       
    }
}

int main(){
    ll n; cin >> n;
    ll arr[n+1];
    for (ll i=1;i<=n;i++){
        cin >> arr[i];
    }
    // hada(4,4,4);
    // for (int i=1;i<=8;i++){
    //     for (int j=1;j<=8;j++){
    //         hada(8,i,j) ;
    //     }
    //     // cout << endl;
    // }

    // for (int i=1;i<=8;i++){
    //     for (int j=1;j<=8;j++){
    //         cout << hadaa[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    ll ans[n+1];
    for (ll i=n; i>=1; i--){
        ll sum = 0;
        for (ll j=n;j>=1;j--){
            if (hadaa[i][j] !=1 && hadaa[i][j] !=-1){
                hadaa[i][j] = hada(n,i,j);
            }
            sum+= arr[j] * hadaa[i][j];
        }
        ans[i] = sum;
        // cout << sum << " ";
    }
    for (ll i=1;i<=n;i++){
        cout << ans[i] << " ";
    }

}