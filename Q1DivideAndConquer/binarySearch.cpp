#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[1000];
    for (int i=0;i<1000 ;i++){
        a[i] = i;
    }
    int l =0; int r = 999;
    int f ; cin >> f;
    while(l< r){
        int mid = (l+r)/2;
        if (a[mid] < f) {
            l = mid+1;
        }
        else {
            r = mid;
        }
    }
    cout << a[l] ;

}
