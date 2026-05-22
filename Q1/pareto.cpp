#include <bits/stdc++.h>
using namespace std;


// vector<pair<int,int>> ans;
vector<pair<int,int>> pareto(int l,int r,const vector<pair<int,int>> &v){
    auto it1 = lower_bound(v.begin(),v.end(),make_pair(l,INT_MIN));
    auto it2 = upper_bound(v.begin(),v.end(),make_pair(r,INT_MAX));
    if (it1 == v.end() || it2 == v.begin()){
        vector<pair<int,int>> x;
        return x;
    }
    if (it2-it1 <= 1){
        vector<pair<int,int>> x;
        auto p = *it1;
        x.push_back(p);
        return x;   
    }
    int mid = (l+r)/2;
    auto v1 = pareto(l,mid,v);
    auto v2 = pareto(mid+1,r,v);
    auto ymax = v2[0].second;
    for (auto i:v1){
        if (i.second > ymax){
            v2.push_back(i);
        }
        else break;
    }
    sort(v2.begin(),v2.end());
    return v2;


}

int main(){
    int n ; cin >> n;
    vector<pair<int,int>> v(n);
    for (int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());
    auto x = pareto(v[0].first,v[n-1].first,v);
    cout << x.size();


}