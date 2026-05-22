#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> q;
    vector<ll> v;

    while(n--){
        ll x; cin >> x;
        q.push_back(x);
    }
    auto it = max_element(q.begin(),q.end());
    ll loop = *it;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    ll count = 3;
    ll time = 3;
    while(time < loop){
        for (ll i=0;i<v[count] ;i++){
            v.push_back(count);
            time++;
            if (time > loop ) break;
        }
        if (time > loop ) break;

        count++;
    }
    for (auto i:q){
        cout << v[i] << '\n';
    }



}