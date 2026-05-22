    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;

    int main(){
        ll n; cin >> n;
        vector<ll> v;
        map<ll,ll> num;
        for (int i=0;i<n;i++) {
            ll x; cin >> x;
            num[x]++;
        }
        set<pair<ll,ll>> s;
        for (auto i: num){
            s.insert({i.second , i.first});
        }

        long long score = 0;
        for (auto i:s){
            if (i.first >1){
                score += i.first * i.first;
            }
        }
        cout << score;
    }