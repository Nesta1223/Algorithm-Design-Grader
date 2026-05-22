#include <bits/stdc++.h>
using namespace std;
int l[200005];
int r[200005];
int dl[200005];
int dr[200005];
int main(){
    //ignore the case where k!=n
    int n,w,k ; cin >> n >> w >> k;
    for (int i=1;i<=n;i++) cin >> l[i];
    for (int i=1;i<=n;i++) cin >> r[i];

    for (int i=1;i<=w+1;i++) dl[i] = l[i];
    for (int i=1;i<=w+1;i++) dr[i] = r[i];

    for (int i=w+2;i<=n;i++){

        for (int j=1; j<=w+1;j++){
            if (i-w-j < 0) break;
            dl[i] = max({dl[i],dr[i-w-j]});
            dr[i] = max({dr[i],dl[i-w-j]});
        }
        dl[i] += l[i];
        dr[i] += r[i];
        // cout << dl[i] << " " << dr[i] << endl;
    }

    // for (int i=1;i<=n;i++) cout << dl[i] << " ";
    // cout << endl;
    // for (int i=1;i<=n;i++) cout << dr[i] << " ";
    // cout << endl;

    int ans = 0;
    for (int i=0;i<=w;i++){
        ans = max({ans,dl[n-i],dr[n-i]});
    }
    cout << ans;
}