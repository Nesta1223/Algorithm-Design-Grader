#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

// unordered_set<pair<int,int>> restrict;

// bool check(vector<int> col,int n){
//     for (int i=0;i<n;i++){
//         for (int k= i+1;k<n;k++){
//             if (col[k] == col[i] + k-i || col[k] == col[i] + i-k) return false;//diagonal check 
//         }
//     }
//     cnt++;
//     return true;
// }
void queen(int step , vector<int> &col , vector<bool> &used,int n  ){
    if (step <n){
        for (int i=0;i<n;i++){
            if (used[i] == false){
                used[i] = true;
                col[step] = i;
                if (step >=1 &&abs(col[step-1] - col[step]) == 1) {
                    used[i] = false;
                    continue;
                }
                queen(step+1, col ,used,n);
                used[i] = false;
            }
        }
    }
    else {
        for (int i=0;i<n;i++) cout << col[i] << " ";
        cout << endl;
        // check(col,n);
        if (step >=1 &&abs(col[step-1] - col[step]) == 1) {
            return;
        }
        cnt++;
        
    }
}


int main(){
    int n; cin >> n;
    vector<int> col(n);
    vector<bool> used(n);
    queen(0,col,used,n);
    cout << cnt;
}