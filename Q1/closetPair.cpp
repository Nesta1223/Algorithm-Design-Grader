#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
vector<pi> v1;
vector<pi> v2;

int dis(pi p1,pi p2){
    return (p1.first-p2.first)*(p1.first-p2.first) + (p1.second - p2.second)*(p1.second - p2.second) ;
}

int cloest(vector<pi> &v){
    int n = v.size();
    if (n<=3){
        int x = INT_MAX;
        for (int i=0;i<n;i++){
            for (int j=i+1 ; j<n;j++){
                x = min(x,dis(v[i],v[j]));
            }
        }
        return x;
    }
    int mid = n/2;
    vector<pi> L;
    vector<pi> R;
    for (int i=0;i<mid ; i++) L.push_back(v[i]);
    for (int i= mid ;i <n;i++) R.push_back(v[i]);
    int b = min(cloest(L) ,cloest(R));
    vector<pi> check;
    for (int i=0;i<n;i++) {
        if ((v[i].first-v[mid].first)*(v[i].first-v[mid].first) <= b){
            pi p  = v[i];
            swap(p.first,p.second);
            check.push_back(p);
        } 
    }
    sort(check.begin(),check.end());
    for (int i= 0 ; i<check.size(); i++){
        for (int j=i+1;j<check.size();j++){
            if (dis(check[i],check[j]) >= b) break;
            else b = min(b,dis(check[i],check[j]));
        }
    }
    return b;

}

int main(){
    vector<pair<int,int>> v;
    int n; cin >> n;
    for (int i=0;i<n;i++){
        pair<int,int> p;
        cin >> p.first >> p.second;
        v.push_back(p);

    }
    sort(v.begin(),v.end());
    int x = cloest(v);
    cout << x;

}