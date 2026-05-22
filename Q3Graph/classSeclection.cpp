#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;

int main(){
    int n; cin >> n;
    for (int i=0;i<n;i++) {
        pair<int,int> p;
        cin >> p.second;
        v.push_back(p);
    }
    for (int i=0;i<n;i++){
        cin >> v[i].first;
    }
    sort(v.begin(),v.end());
    int cnt = 0;
    int lastback = 0;
    for (auto i: v){
        if (i.second >= lastback){
            cnt ++;
            lastback = i.first;
        }
    }
    cout << cnt;




}