#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    ios_base::sync_with_stdio(false);  cin.tie(NULL);
    int n,k,m; cin >> n >> k >> m ;
    vector<ll> v(n+1);
    vector<ll> sum(n+1);
    ll s = 0;
    for (int i=1 ; i<= n;i++){
        int x;
        cin >> x;
        v[i] = x;
        s-=m;
        s+= x;
        sum[i] = s;

    }
    // for (auto i : sum) cout << i << ' ';
    // cout << endl;
    for (int i=0 ; i<k;i++){
        ll start,goal ; cin >> start >> goal;
        ll check = sum[start-1] + goal;
        auto it = lower_bound(sum.begin(),sum.end(),check);
        cout << it - sum.begin() << '\n';
    }

}  