#include <bits/stdc++.h>
using namespace std;

int arr[2000000];


int punk(int start,int stop){
    if (start == stop ) return arr[start];
    int mid = (start+stop) /2;
    bool left = true;
    bool right = true;
    int check = arr[start];
    for (int i=start;i<= mid;i++){
        if (check != arr[i]) left = false;
    }
    check = arr[mid+1];

    for (int i=mid+1;i<= stop;i++){
        if (check != arr[i]) right = false;
    }
    if (left){
        int x= arr[start];
        int y = punk(mid+1,stop);
        if (y == x+1) return x;
    }
    if (right){
        int x= arr[mid+1];
        int y = punk(start,mid);
        if (y == x+1) return x;
    }
    return -1;

}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    int t; cin >> t;
    while(t--){
        int k,x ; cin >> k >> x;
        int num = pow(2,k);
        for (int i=1;i<=num;i++){
            cin >> arr[i];
        }
        int y = punk(1,num);
        if (x==y) cout << "YES" << '\n';
        else cout << "NO" << '\n';


    }
}