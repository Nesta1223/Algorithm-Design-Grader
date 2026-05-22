#include <bits/stdc++.h>
using namespace std;

int arr[10000][10000];
int c[10000];
int a[10000];

int recur(int n,int k){
    int ans =0;
    if (n<k) ans = a[n] % 32717;
    else{
        ans = 0;
        for (int i=1;i<=k;i++){
            int y = arr[n-i][k];
            if (arr[n-i][k] == 0) y = recur(n-i,k)%32717;
            ans += ((c[i]%32717) * (y %32717))%32717;
        }
        ans %= 32717;

    }
    arr[n][k] = ans;
    return ans;

}

int main(){
    int k,n; cin >> k >> n;
    for (int i=0;i<k;i++) cin >> c[i+1];
    for (int i=0;i<k;i++) cin >> a[i];
    int x= recur(n,k);
    cout << x;
}