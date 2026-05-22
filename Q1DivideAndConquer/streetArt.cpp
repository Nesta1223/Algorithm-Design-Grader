#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> v;

ll para(ll a, ll b,ll c){
    auto it = lower_bound(v.begin(),v.end(),b);
    auto it2 = upper_bound(v.begin(),v.end(),c);
    ll x = it2-it;
    if (x<=0) return 0;
    if (c-b+1 <3 ) return max(x,0LL);

    ll u = (c-b+1)/3;
    ll w = (c-b+2)/3;
    ll y1 = para(a+1,b,b+u-1);
    ll y2 = para(a+2,b+u,b+u+w-1);
    ll y3 = para(a+3,b+u+w,c);
    return x + max(y1+y2,max(y2+y3,y1+y3));

}

int main(){
    ll w,n;
    cin >> w >> n;
    for (int i=0;i<n;i++){
        ll x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    cout << para(0,1,w);

}