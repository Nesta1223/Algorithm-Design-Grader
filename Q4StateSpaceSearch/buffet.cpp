#include <bits/stdc++.h>
using namespace std;
int arr[100005];

int main(){
    int f,w,n; cin >> f >> w >> n;
    vector<int> food;
    for (int i=0;i<f;i++){
        int a; cin >> a;
        arr[a] = 1;
    }
    int cnt = 0;
    int track = 1;
    while(track <= n){
        if (arr[track] == 1){
            cnt++;
            track+= 2*w;
            track++;
        }
        else{
            track++;
        }
    }
    cout << cnt;

}