#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,m ; cin >>n >>m;
    ll chief[n+1] ;
    for (ll i=1;i<=n;i++){
        cin >> chief[i];
    }
    for (ll i=0;i<m;i++){
        ll q; cin >> q;
        ll l = 0;
        ll r = 1e18;
        while(l<r){
            ll mid = (l+r)/2;
            ll sum = n;
            for(ll j=1;j<=n;j++){
                sum += mid/chief[j];
            }
            if (sum < q) l = mid+1;
            else r = mid;
        }
        cout << l <<"\n";

    }
}