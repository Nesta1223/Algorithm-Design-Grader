#include <bits/stdc++.h>
using namespace std;

struct girl{
    int p;
    int s;
    bool operator< (const girl &g) const{
        return this->p - this->s < g.p - g.s;
    }
};

girl arr[100005];

int main(){
    int n; cin >> n;
    for (int i=1; i<= n;i++){
        girl g;
        cin >> g.p >> g.s;
        arr[i] = g;
    }
    sort(arr+1 , arr+n+1);
    long long ans =0;
    for (int i=1;i<=n ;i++) {
        ans+= arr[i].p * (i-1);
        ans+= arr[i].s * (n-i);
    }
    cout << ans;
}