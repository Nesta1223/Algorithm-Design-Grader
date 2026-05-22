#include <bits/stdc++.h>
using namespace std;


int a[100001];
int b[100001][1001];
int R[100001];



// int recur(int n,int k){
//     if (n<= 0){
//         return 0;
//     }
//     if (n<=k){
//         R[n] = a[n]%32717;
//         return R[n]%32717;
//     }
//     if (R[n] != -1 ) return R[n];
//     else{
//         long long ans= 0;
//         int p = b[n][0];
//         for (int i=1;i<= p ; i++){
//             if (R[n-b[n][i]] != -1) ans+= R[n-b[n][i]]%32717;
//             else {
//                 R[n-b[n][i]] = recur(n-b[n][i],k)%32717;
//                 ans+= R[n-b[n][i]]%32717 ;
//             }
//             ans%=32717;
//         }
//         R[n] = ans%32717;
//         return R[n]%32717;

//     }
    
    


// }

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,k ; cin >> n >> k;
    for (int i=1;i<=k;i++){
        cin >> a[i];
        R[i] = a[i];
        cout << R[i] << " ";
    }
    // for (int i=0;i<=100000;i++){
    //     R[i] =-1;
    // }


    for (int i=k+1 ; i<= n;i++){
        int p; cin >> p;
        b[i][0] = p;//b[i][0] store # of b[i][j]]
        R[i] = 0;
        for (int j = 1; j<= p ;j++){
            cin >> b[i][j];
            if (i-b[i][j] <=0) ;
            else R[i] += R[i-b[i][j]];
            R[i] %= 32717;
        }
        cout << R[i] << " ";
    }

    // for (int i=k+1;i<=n;i++){
    //     cout << b[i][0] << " ";
    //     for (int j=1;j<=b[i][0];j++) cout << b[i][j] << " " ;
    //     cout << '\n';
    // }
    

}