#include <bits/stdc++.h>
using namespace std;

int arr[1000005];

int main(){
    int n,l ; cin >> n >> l;
    for (int i=1;i<=n;i++){
        int a; cin >> a;
        arr[a] = 1;
    }
    int track = 1;
    int cnt = 0;
    while(track <=1000000){
        if (arr[track] == 1){
            cnt++;
            track+=l;
        }
        else{
            track++;
        }
    }
    cout << cnt;
}