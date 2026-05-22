#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    int arr[100100];
    for (int i=1;i<=n;i++){
        cin >> arr[i];
    }
    for (int i=0;i<m;i++){
        int q ; cin >> q;
        int l = 1;
        int r = n;
        while (l<r){
            int mid = (l+r)/2;
            if (arr[mid] < q) l= mid+1;
            else r = mid;
        }
        if (l!=1) {
            if (arr[l] == q || q > arr[n]) cout << arr[l] << "\n";
            else cout << arr[l-1] << "\n"; 
        }
        else{
            if (arr[l] == q) cout << arr[l] << "\n";
            else cout << -1 << "\n"; 
        }
    }
}