#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll arr[500005];
ll dp[500005];
ll dpLeft[500005];
ll dpRight[500005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n; cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> arr[i];
    }
    dp[1] = arr[1];
    ll start = 1;
    ll stop =1;
    ll start1 = 1;
    ll stop1 = 1;
    ll ans = arr[1];
    for (ll i=2;i<=n;i++){
        if (dp[i-1] > 0){
            dp[i] = dp[i-1] + arr[i];
            stop1++;
        }
        else {
            dp[i] = arr[i];
            start1 = i;
            stop1 = i;
        }
        if (dp[i] >= ans){//track narrowness later
            ans = dp[i];
            start = start1;
            stop = stop1;
        }
    }
    // 1 to start-1
    ll ansLeft = 0;
    if (start > 1){
        ansLeft = arr[1];
        dpLeft[1] = arr[1];
        for (ll i=2;i<=start-1;i++){
            dpLeft[i] = max(dpLeft[i-1]+arr[i],arr[i]);
            ansLeft = max(ansLeft,dpLeft[i]);
        }
    }
    // cout << "left" << ansLeft << " ";

    //stop+1 to n
    ll ansRight =0;
    if (stop < n){
        ansRight = arr[stop+1];
        dpRight[stop+1] = arr[stop+1];
        for (ll i=stop+2;i<=n;i++){
            dpRight[i] = max(dpRight[i-1]+arr[i],arr[i]);
            ansRight = max(ansRight,dpRight[i]);
        }
    }
    if ((ansLeft >0 || ansRight >0) ){
        ans += max(ansLeft,ansRight);
    }
    cout << ans    ;
    // cout << start << " " << stop ;
}