#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int arr[5];

int eiei(ll row , ll col , int n){
    if (n==1){
        if (row==1 && col== 1) return arr[1];
        if (row==1 && col== 2 ) return arr[2];
        if (row==2 && col== 1) return arr[3];
        if (row==2 && col== 2) return arr[4];
    }
    if (row <= 1LL << (n-1) && col <= 1LL << (n-1)){
        return eiei(row,col,(n-1));
    }
    else if (row <= 1LL << (n-1) && col > 1LL << (n-1)){
        return eiei(col- (1LL << (n-1) ),row,(n-1));
    }
    else if (row > 1LL << (n-1) && col <= 1LL << (n-1)){
        return -eiei(row- (1LL << (n-1)),col,(n-1));
    }
    else if (row > 1LL << (n-1) && col > 1LL << (n-1)){
        return -eiei(col- (1LL << (n-1)) ,row- (1LL << (n-1)),(n-1));
    }
}


int main(){
    int n,m; cin >> n >> m;
    for (int i=1;i<=4;i++){
        cin >> arr[i];
    }
    for (int i=0;i<m;i++){
        ll row,col; cin >> row >> col;
        int x = eiei(row,col,n);
        cout << x <<'\n';
    }
}