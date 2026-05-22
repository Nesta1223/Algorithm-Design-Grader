#include <bits/stdc++.h>
using namespace std;    
using ll = long long;

int dp[100100];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,q; cin >> n >> q;
    map<ll,ll> store;
    for (ll i=0;i<n;i++){
        ll x,c;
        cin >> x >> c;
        store[x] += c;
    }
    map<ll,ll> pos;
    ll count =1;
    for (auto i: store){
        pos[count] = i.first;
        count+=i.second;
    }
    for (ll i=0;i<q;i++){
        ll index ; cin >> index;
        auto it = pos.lower_bound(index+1);
        it--;
        cout << it->second << "\n";
    }
}