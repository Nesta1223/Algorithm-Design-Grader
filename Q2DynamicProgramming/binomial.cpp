#include <bits/stdc++.h>
using namespace std;

int arr[100][100];

int combi(int n,int k){
    if (k==0 || n==k) return 1;
    if (arr[n][k] != 0)  return arr[n][k];
    int x= combi(n-1,k) + combi(n-1,k-1);
    arr[n][k] = x;
    return x;
}

int main(){
    int n,k; cin >> n >> k;
    cout << combi(n,k);
}