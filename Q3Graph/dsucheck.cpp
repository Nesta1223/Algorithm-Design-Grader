#include <bits/stdc++.h>
using namespace std;


int parent[1000005];
int dp[1000005];
int cnt[1000005];

int find(int a){
    if (dp[a]) {
        if (dp[a] == 1e9 ) return 1e9;
        else return dp[a];
    }
    int start = a;
    unordered_set<int> path;
    path.insert(start);
    while(parent[a] != -1){
        a = parent[a];
        if (path.find(a) != path.end()) {
            for (auto i: path){
                dp[i] = 1e9;
            }
            return 1e9;
        }
        path.insert(a);
    }
    for (auto i: path){
        dp[i] = a;
    }
    return a;   
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    int n,q ; cin >> n >> q;
    while(q--){
        memset(dp,0 , sizeof dp);
        memset(cnt,0 , sizeof cnt);
        for (int i=1;i<=n;i++){
            cin >> parent[i];
        }
        bool nope = false;
        for (int i=1;i<=n;i++){
            if (find(i) == 1e9){
                nope = true;
                break;
            }
        }

        // for (int i=1;i<=n;i++) cout << dp[i] << " ";
        // cout << endl;



        if (nope) cout << 0 << " " << 0 << '\n';
        else{
            for (int i=1;i<=n;i++) {
                cnt[dp[i]]++;
            }
            int ans = 0;
            for (int i=1;i<=n;i++){
                ans = max(ans,cnt[i]);
            }

            cout << 1 << " " << ans << '\n';    
        }
    }
}