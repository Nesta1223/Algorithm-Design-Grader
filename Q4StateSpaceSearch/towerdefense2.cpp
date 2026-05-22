#include <bits/stdc++.h>
using namespace std;


vector<pair<int,int>> mon(200005);
int t[200005];

int main(){
    int n,m , tower , w ; cin >> n >> m >> tower >> w;
    int sumhp = 0;
    for (int i=1;i<=m;i++) cin >> mon[i].first;
    for (int i=1;i<=m;i++) {
        cin >> mon[i].second;
        sumhp+= mon[i].second;
    }
    sort(mon.begin() + 1,mon.begin() + m + 1);
    for (int i=1;i<= n;i++){
        if (tower == 0) break;
        int lshoot = max(i-w, 0);
        int rshoot = min(i+w,n);
        auto it  = lower_bound(mon.begin() + 1,mon.begin()+m+1, make_pair(lshoot,-1));//lower bound
        int idx = it - mon.begin();

        
        while(mon[idx].second == 0 && idx < m){
            idx++;
        }
        // if (i==4) cout << idx  << " " << mon[idx].first << ' ' << lshoot << ' ' << rshoot << " ";

        if (mon[idx].first >= lshoot && mon[idx].first <= rshoot){
            // cout << i << " " << idx << endl;
            mon[idx].second--;
            sumhp--;
            tower--;
        }
        

        

    }

    // cout << endl;
    cout << sumhp;


}