#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll T(ll n){
    if (n==1) return 1;
    return 4*T(n-1) +n;
}

int main(){
    for (ll i=1 ;i<=100;i++){
        cout << T(i) << endl;
    }
}