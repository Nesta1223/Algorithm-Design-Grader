#include <bits/stdc++.h>
using namespace std;

int dp[10005];
int arr[10005];
int jump(int k,int n,int m,int &count){ 
    if (dp[n] == 0) return dp[n]; 
    if (dp[n] == 1){
        count++;
        return dp[n];
    }

    if (n>k){
        return 0;
    }
    if (n==k){
        count++;
        count%=1000003;
        dp[n] = 1;
        return 1;
    }

    bool success = false;
    for(int i=1;i<=m;i++){
        int x = jump(k,n+arr[i],m,count);
        if (x==1) {
            success = true;
        }
        dp[arr[i]] = x;
    }
    if (success) {
        dp[n] = 1;
        // count++;
    }
    else dp[n] = 0;
    return dp[n];
}

int main(){
    int n,m; cin >> n >>m;
    for (int i=0;i<10005;i++) dp[i]=-1;
    for (int i=1;i<=m;i++){
        cin >> arr[i];
    }
    int count =0;
    jump(n,0,m,count);
    cout << count;

}