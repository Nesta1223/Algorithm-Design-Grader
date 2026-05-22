#include <bits/stdc++.h>
using namespace std;

int arr[1000001];

int b[1000001];

int jump(int n){

}

int main(){
    int n ; cin >> n;
    for (int i=1;i<=n;i++) cin >> arr[i];
    b[1] = arr[1];  
    b[2] = arr[1] + arr[2];
    b[3] = max(arr[1]+ arr[2]+ arr[3], arr[1]+arr[3]);
    for (int i=4;i<=n;i++){
        b[i] = arr[i] + max(b[i-3],max(b[i-2],b[i-1]));
    }
    cout << b[n];
}