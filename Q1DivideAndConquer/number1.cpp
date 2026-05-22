#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int one(ll n,ll l, ll r){
    if (r<l || r<1) return 0;
    if (n==1 || n==0) return n; 
    ll up = log2(n) +1;
    // cout << up << endl;
    ll parent = (1 << up) -1;
    if (l > parent ) return 0;
    ll mid = (parent/2)+1;
    int x;
    if (mid >= l && mid <=r) x = n%2;
    else x=0;
    return one(n/2,l,min(r,mid-1))+ x + one(n/2,max(1LL,l-mid),r-mid) ;
}

int main(){
    ll n,l,r;
    cin >> n >> l >> r;
    int x = one(n,l,r);
    cout << x;
}