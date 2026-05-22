#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[500005];
ll ep[500005];
ll a[500005];


int main(){
  int n; cin >> n;
  for (int i=1;i<=n;i++) cin >> a[i];
  if (n==1) cout << a[1];
  else{
      ll ans = INT_MIN;
      for (int i=1;i<=n;i++){
        ll adder;
        if (i%2==1){
          adder = a[i];
          dp[i] = max(dp[i-1]+adder,adder);
          ans = max(ans,dp[i]);
        }
        else{
          adder = -a[i];
          dp[i] = dp[i-1]+ adder;
        }
      }
      for (int i=2;i<=n;i++){
        ll adder;
        if (i%2==0){
          adder = a[i];
          ep[i] = max(ep[i-1]+adder,adder);
          ans = max(ans,ep[i]);
        }
        else{
            adder = -a[i];
            ep[i] = ep[i-1]+ adder;
        }
      }
      cout << ans;
  }
  
}