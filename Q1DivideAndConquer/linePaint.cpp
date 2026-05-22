#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    set<pair<ll,ll>> s;
    for (ll i=0;i<n;i++){// 7 4   20 10
        ll l,r;
        cin >> l >> r;
        auto it = s.lower_bound(make_pair(l-1,-1));
        ll ansl = l;
        ll ansr = r;
        auto it2 = it;
        if (it!=s.begin()) it2--;

        while( !((r+1 < it->second) ||(l-1 > it->first) )
         && it != s.end() ){
            ansl = min(ansl,it->second);
            ansr = max(ansr,it->first);
            it = s.erase(it);
        }
        s.insert(make_pair(ansr,ansl));
    }
    for (auto i:s){
        cout << i.second << " " << i.first << " ";
    }
}