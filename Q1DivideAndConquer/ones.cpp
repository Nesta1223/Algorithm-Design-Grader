#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> v = {0,1,11,111,1111,11111,111111,1111111,11111111,111111111,1111111111};
ll play(ll n){
    if (n<= 0) return 0;
    if (n==1) return 1;
    if (n==2 || n==11) return 2;
    if (n==3 || n==10) return 3;
    if (n==4 || n==9) return 4;
    if (n==5 || n==8) return 5;
    if (n==6 || n==7) return 6;

    auto it = lower_bound(v.begin(),v.end(),n);
    int idx1 = it - v.begin();
    int idx2 = idx1-1;
    if (v[idx1] == n) return idx1;
    ll x1 = v[idx1];
    ll x2 = v[idx2];
    ll m1 = x1 - n;
    ll g =  n/x2;
    ll m2 = n- g*x2;
    // return min(idx1 + play(x1-n), g*idx2 + play(m2));
    // idx2 * g <= idx1 + (x1-n)/x2
    if (idx2 * g > idx1 + (x1-n) * idx2 /x2  ){
        return idx1+play(m1);
    }
    else{
        return (g*idx2)+play(m2);
    }
}
//77 -> 14,10
//66 -> 12,12
//67 ->13,13

int main(){
    ll n ; cin >> n;
    ll x = play(n);
    cout << x;
}