#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> v;
    vector<ll> money;
    vector<ll> grass;
    ll mo=0; ll g = 0;
    for (int i=0;i<n;i++){
        int x ; cin >> x;
        v.push_back(x);
        mo+=x+k;
        g+=x;
        money.push_back(mo);
        grass.push_back(g);
    }


    // for (auto i: money) cout << i << " ";
    // cout << endl;

    for (int j=0;j<m;j++){
        ll a,b ; cin >> a >> b;
        int x= 0;
        if (a !=0 ){
            b+=money[a-1];
            x= grass[a-1];
        }
        auto it = upper_bound(money.begin()+a,money.end(),b);
        if(it!= money.begin()+a){
            it--;
            int idx = it-money.begin();
            cout << grass[idx]-x << '\n';

        }
        else{
            cout << 0 << '\n';
        }
    }
}