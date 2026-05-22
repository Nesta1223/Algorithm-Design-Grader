#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;

void partition(ll n,vector<pi> &v){
    while(n!=1){
        if (n%2==1) v.push_back(make_pair(1,n/2));
        else v.push_back(make_pair(0,n/2));
        n/=2;
    }
}

int main(){
    ll n,k ; cin >> n >> k;
    vector<pi> v;
    partition(n,v);
    ll a,b,c,d; cin >> a >> b >> c >> d;
    // cout << "yay";
    // for (auto i: v) cout << i.first << "," << i.second << " ";
    // cout << endl;
    ll a0 = a;
    ll b0 = b;
    ll c0 = c;
    ll d0 = d;
    for(ll i= v.size()-1 ; i>= 0; i--){
        ll a1 = (a*a)+(b*c);
        ll b1 = (a*b)+(b*d);
        ll c1 = (a*c)+(d*c);
        ll d1 =(b*c)+(d*d);
        a = a1%k; b= b1%k; c=c1%k;d=d1%k;
        if((v[i].first)==1){
            ll a1 = (a*a0)+(b*c0);
            ll b1 = (a*b0)+(b*d0);
            ll c1 = (a0*c)+(d*c0);
            ll d1 =(b0*c)+(d*d0);
        a = a1%k; b= b1%k; c=c1%k;d=d1%k;
        }
    }
    cout << a << " " << b << " " << c << " " << d;
}