#include <bits/stdc++.h>
using namespace std;

int arr[16777216];

void makeZero(int n,int count){
    if (arr[0] != 0 && count >= arr[0]) return;
    // if (arr[n]==0) arr[n] = count;
    // else{
    //     if (count >= arr[n]) return;
    //     else arr[n] = count;
    // }
    
    if (count >= arr[n] && arr[n] !=0) return;
    else arr[n] = count;

    
    if (n==0) return;
    makeZero((n*2) % 16777216,count+1);
    makeZero((n+1)% 16777216,count+1);

}

int main(){
    int n ; cin >> n;
    makeZero(n,0);
    cout << arr[0];
}