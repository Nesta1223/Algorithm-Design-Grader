#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m ,k ,w;
    cin >> n >> m >> k >> w;
    int a[n+w];
    int hp[n+w];
    vector<pair<int,int>> pos;
    for (int i=0;i<m;i++){
        int p ; cin >> p;
        pos.push_back(make_pair(p,0));
    }
    for (int i=0;i<m;i++){
        int h ; cin >> h;
        pos[i].second = h;
    }
    sort(pos.begin(),pos.end());
    for (int i=0;i<k;i++){
        int t ; cin >> t;
        auto p1 = lower_bound(pos.begin(),pos.end(),make_pair(t,INT_MIN));
        auto p2 = p1;
        p2--;
        if (p1->first <= t+w && p1->second!=0) p1->second--;
        else if (p2->first >= t-w && p2->second!=0) p2->second--;
    }
    int sum =0;
    for (auto i : pos){
        sum +=i.second;
    }
    cout << sum;
}