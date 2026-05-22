#include <bits/stdc++.h>
using namespace std;
using ll = long long;



ll mat[4][4];
ll origin[4][4];
ll mod = 100000007;


//Is this overflow?
void partition(ll n,vector<int> &v){
    while(n!=1){
        if (n%2==1) v.push_back(1);
        else v.push_back(0);
        n/=2;
    }
}


int main(){
    ll n; cin >> n;
    ll count =0;
    n-=2;
    mat[1][1] = 1;
    mat[1][3] = 1;
    mat[2][1] = 1;
    mat[2][2] = 1;
    mat[3][2] = 1;

    vector<int> v;
    partition(n,v);


    for (int i=1;i<=3;i++){
        for (int j=1;j<=3;j++){
            origin[i][j] = mat[i][j];
        }
    }

    for (int i=v.size()-1 ; i>=0;i--){
        ll tmp[4][4] ;
        for (int i=1;i<=3;i++){
            for (int j=1;j<=3;j++){
                tmp[i][j] = mat[i][j];
            }
        }
        for (int i=1;i<=3;i++){
            for (int j=1;j<=3;j++){
                mat[i][j] = ( (tmp[i][1]*tmp[1][j]) %mod+ (tmp[i][2]*tmp[2][j])%mod + (tmp[i][3]*tmp[3][j])%mod)%mod;
            }
        }
        for (int i=1;i<=3;i++){
            for (int j=1;j<=3;j++){
                tmp[i][j] = mat[i][j];
            }
        }
        if (v[i]==1){
            for (int i=1;i<=3;i++){
                for (int j=1;j<=3;j++){
                    mat[i][j] = ((tmp[i][1]*origin[1][j])%mod + (tmp[i][2]*origin[2][j])%mod + (tmp[i][3]*origin[3][j])%mod)%mod;
                }
            }            
        }
    }
    // for (int i=1;i<=3;i++){
    //     for (int j=1;j<=3;j++){
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ll ans = 0;
    for (int i=1;i<=3;i++){
        ans += (  (mat[i][1]*1)%mod + (mat[i][2]*2)%mod + (mat[i][3]*1)%mod);
        ans%=mod;
    }
    cout << ans;
}