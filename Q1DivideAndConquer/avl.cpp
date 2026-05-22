#include <bits/stdc++.h>
using namespace std;

int depth[50001];
vector<pair<int,int>> v(50000+1);
vector<pair<int,int>> ans;
void recur(int k,){
    if (k==0) {
        pair<int,int> p;
        p.first = start;
        p.second = current;
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    for (int i=1;i<=n-1;i++){
        int l,r;
        cin >> l >> r;
        if (v[l].first == 0) v[l].first = r;
        else v[l].second = r;
    }

    
}