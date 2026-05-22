#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m ; cin >> n >>m;
    int a[n];
    for (int i=0;i<n;i++){
        cin >> a[i];
    }               
    for (int i=0;i<m;i++){
        int x; cin >> x;
        int l = 0;
        int r = n-1;
        while(l!=r){
            int mid = (l+r)/2;
            if (a[mid] < x) l = mid +1;
            else r = mid;
        }
        if(x<a[l]) cout << l-1 << endl;
        else {
            while(l+1 != n && x== a[l] && x==a[l+1]) l++;
            cout << l << endl;
        }
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
}