#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    vector<int> v;
    for (int i=0;i<n;i++){
        int x ; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    ll score = 0;
    for (int i=0 ; i< v.size()-1 ; i++){
        score+= v[i] * v[i+1];
    }
    cout << score;
}