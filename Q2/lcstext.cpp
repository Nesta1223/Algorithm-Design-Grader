#include <bits/stdc++.h>
using namespace std;


int dp[1005][1005];

int trash[1];
string s1 ;
string s2;
string arr[1];


int lcs(int a , int b){
    if (dp[a][b] != -1  ) return dp[a][b];
    if (a==0 | b==0) {
        dp[a][b] = 0;
        return 0;
    }
    int ans ; 
    if (s1[a-1] == s2[b-1]){
        ans = lcs (a-1,b-1) +1;
        arr[0] += s1[a-1];
    } 
    else{
        ans = max (lcs (a-1,b),lcs (a,b-1));
    }
    dp[a][b] = ans;
    return ans;


}

int main(){
    int n1, n2 ; cin >> n1 >> n2;
    cin >> s1 >> s2;
    arr[0] = "";
    for (int i=0; i<1005;i++){
        for (int j = 0 ; j< 1005; j++){
            dp[i][j] = -1;
        }
    }
    for (int i=0; i<= n1;i++){
        for (int j = 0 ; j<= n2; j++){
            cin >> trash[0];
        }
    }
    lcs(n1,n2);

    cout << arr[0];


}