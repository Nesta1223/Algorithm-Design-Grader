#include <bits/stdc++.h>
using namespace std;
int arr[400000];
int s[400000];

// int eiei(int start,int stop){
//     if (start == stop){
//         return arr[start];
//     }
//     int mid = (start+stop)/2;
//     int r1 = eiei(start,mid);
//     int r2 = eiei(mid+1,stop);
//     int r3 = INT_MIN;
//     for (int i=start;i<=mid;i++){
//         for (int j=mid+1;j<=stop;j++){
//             if (arr[i] == arr[j]){
//                 r3 = max(r3,s[j] - s[i-1]);
//             }
//         }
//     }
//     return max(r1,max(r2,r3));
// }

// void solve(int n){
//     vector<int> a;
    
// }


int main(){
    int n ; cin >> n;
    int total = 0;
    for (int i=1;i<=n;i++){
        cin >> arr[i];
        total += arr[i];
        s[i] = total;
    }
    map<int,int> m;
    int ans =-1E9;
    int tmp;
    for (int i=1;i<=n;i++){
        tmp = -1;
        if (m.find(arr[i]) == m.end()) {
            m[arr[i]] = i;
            ans = max(ans,arr[i]);
        }
        else{
            int x = arr[i];
            tmp  = s[i] - s[m[x] -1];
            ans  = max(tmp,ans);
            if (tmp <0){
                m[x] = i;
            }
        }
    }
    cout << ans;

}
