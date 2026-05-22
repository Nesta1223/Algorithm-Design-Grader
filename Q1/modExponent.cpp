#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll recur(ll x,ll n,ll k){
    if (n==1) return x%k;
    if (n%2 ==0){
        return (recur(x,n/2,k)*recur(x,n/2,k))%k;
    }
    else{
        return (recur(x,n/2,k)*recur(x,n/2,k)*x)%k;
    }
}

int main(){
    ll x,n,k; cin >> x >> n >>k;
    cout << recur(x,n,k);

}