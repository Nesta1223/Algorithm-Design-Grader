#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll check(const ll &start,const ll &stop,const ll &a,const ll& b,const vector<ll>& avenger){
    if (start == stop){
        auto it1 = lower_bound(avenger.begin(),avenger.end(),start);
        auto it2 = upper_bound(avenger.begin(),avenger.end(),stop);
        if(it1 == avenger.end() || it2 == avenger.begin())  {
            return a;
        }
        else{
            ll m = it2 - it1;
            if (m<=0){
                return a;
            } 
            else {
                return b*(it2-it1);
            }
        }
    }
    auto it1 = lower_bound(avenger.begin(),avenger.end(),start);
    auto it2 = upper_bound(avenger.begin(),avenger.end(),stop);
    if(it1 == avenger.end() || it2 == avenger.begin() || it2-it1 <=0)  {
        return a;
    }
    ll x1 = b*(it2-it1) * (stop-start+1);
    ll mid = (start+stop)/2;
    auto it3 = upper_bound(avenger.begin(),avenger.end(),mid);
    auto it4 = lower_bound(avenger.begin(),avenger.end(),mid+1);
    ll x2 = 0;
    if(it1 == avenger.end() || it3 == avenger.begin() || it3-it1 <=0)  {
        x2 +=a;
    }
    else{
        x2+=b*(it3-it1) * (mid-start+1);
    }
    if(it4 == avenger.end() || it2 == avenger.begin() || it2-it4 <=0)  {
        x2+=a;
    }
    else{
        x2+=b*(it2-it4) * (stop-mid);
    }
    if (x1<=x2) {
        return x1;
    }
    else{
        ll y = min(x2,check(start,mid,a,b,avenger) + check(mid+1,stop,a,b,avenger));
        return y;
    }
    
}





int main(){
    ll p,k,a,b; cin >> p >> k >> a >> b;
    vector<ll> avenger;
    while(k--){
        ll pos; cin >> pos;
        avenger.push_back(pos);
    }
    sort(avenger.begin(),avenger.end());
    ll x = check(1,pow(2,p),a,b,avenger);
    cout << x;
}   