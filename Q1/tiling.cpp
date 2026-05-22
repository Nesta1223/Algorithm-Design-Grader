#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll,pair<ll,ll>>;
set<pi> s;

void eiei(ll l, ll x, ll y,ll x0,ll y0){
    if (l == 2){
        ll a = x-x0;
        ll b = y-y0;
        pi p;
        if (a==0 && b==0 ) p.first = 0;
        if (a==1 && b==0 ) p.first = 1;
        if (a==0 && b==1 ) p.first = 2;
        if (a==1 && b==1 ) p.first = 3;
        if (a==1) x--;
        if (b==1) y--;
        p.second.first = x;
        p.second.second = y;
        s.insert(p);
        return;
    }
    bool q1 = x-x0<l/2 && y-y0 <l/2;
    bool q2 = x-x0>=l/2 && y-y0 <l/2;
    bool q3 = x-x0<l/2 && y-y0>=l/2;
    bool q4 = x-x0>=l/2 && y-y0>= l/2;
    if (q1){
        s.insert(make_pair(0,make_pair(x0+(l/2)-1,y0+(l/2)-1)));
        eiei(l/2,x,y,x0,y0);
        eiei(l/2,x0+(l/2),y0+(l/2)-1,x0+l/2,y0);
        eiei(l/2,x0+(l/2)-1,y0+(l/2),x0,y0+l/2);
        eiei(l/2,x0+(l/2),y0+(l/2),x0+l/2,y0+l/2);
    
    }
    if (q2){
        s.insert(make_pair(1,make_pair(x0+(l/2)-1,y0+(l/2)-1)));
        eiei(l/2,x0+(l/2)-1,y0+(l/2)-1,x0,y0);
        eiei(l/2,x,y,x0+l/2,y0);
        eiei(l/2,x0+(l/2)-1,y0+(l/2),x0,y0+l/2);
        eiei(l/2,x0+(l/2),y0+(l/2),x0+l/2,y0+l/2);
    
    }
    if (q3){
        s.insert(make_pair(2,make_pair(x0+(l/2)-1,y0+(l/2)-1)));
        eiei(l/2,x0+(l/2)-1,y0+(l/2)-1,x0,y0);
        eiei(l/2,x0+(l/2),y0+(l/2)-1,x0+l/2,y0);
        eiei(l/2,x,y,x0,y0+l/2);
        eiei(l/2,x0+(l/2),y0+(l/2),x0+l/2,y0+l/2);
    }
    if (q4){
        s.insert(make_pair(3,make_pair(x0+(l/2)-1,y0+(l/2)-1)));
        eiei(l/2,x0+(l/2)-1,y0+(l/2)-1,x0,y0);
        eiei(l/2,x0+(l/2),y0+(l/2)-1,x0+l/2,y0);
        eiei(l/2,x0+(l/2)-1,y0+(l/2),x0,y0+l/2);
        eiei(l/2,x,y,x0+l/2,y0+l/2);
    }
}

int main(){
    ll l,x,y;
    cin >> l >> x >> y;
    eiei(l,x,y,0,0);
    cout << s.size() << '\n';
    for (auto i: s){
        cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
    }


}