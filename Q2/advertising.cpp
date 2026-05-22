#include <bits/stdc++.h>
using namespace std;
int arr[10005];
int dp[10005];

int jump(int start,int n){
    if (start >= n) return arr[start] ;

    // int a;
    // if (dp[start+4] != -1) a= dp[start+4];
    // else  a = jump(start+4,n);    


    int x;
    if (dp[start+3] != -1) x= dp[start+3];
    else  x = jump(start+3,n);

    int y ;
    if (dp[start+2] != -1) y = dp[start+2];
    else y = jump(start+2,n);



    int z = max({x,y});
    dp[start] = arr[start] + z;
    return dp[start];

}

int main(){
    int n; cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    for (int i=0;i<10005;i++) dp[i] = -1;
    int x = jump(1,n);
    int y = jump(2,n);
    cout << max(x,y);
}