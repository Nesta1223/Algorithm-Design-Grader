#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string check (ll y,ll n,ll x){
    if (y==0){
        if (n==1) return "g";
        else return "a";
    }
    ll a = (x-y-3)/2 ;
    if (n >= a+1 && n<= a+y+3){
        if (n== a+1) return "g";
        else return "a";
    }
    else if (n<= a){
        return check(y-1,n,(x-y-3)/2);
    }
    else{
        return check(y-1,n-y-a-3,(x-y-3)/2);
    }
}

int main(){
    ll n; cin >> n;
    ll x= 3;
    ll y =0;
    while (x<n){
        x = 2*x+ (y+1)+3;
        y++;                           
    }
    // cout << y;
    string a = check(y,n,x);
    cout << a;
}