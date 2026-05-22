#include <bits/stdc++.h>
using namespace std;

int arr[105];
int closes = 1e9;
int used[105];


void go (int start , int step ,int n, int m , int k, int current){
    if (step == m) {
        closes = min ( closes , abs(current -k));
        return;
    }
    if (current - k > closes) return;
    // if(start+1 >)
    for (int i=start-1 ;i>= 1 ; i--){
        if (!used[i]){
            used[i] = 1;
            go(i,step+1 , n , m , k, current + arr[i]);
            used[i] = 0;
        }
    }



}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m , k ; cin >> n >> m >> k;
    for (int i=1;i<=n;i++) cin >> arr[i];
    sort(arr+1 , arr+n + 1);
    // int ans = 0; 
    go(n+1 , 0 ,n ,m ,k , 0);
    cout << closes;
}