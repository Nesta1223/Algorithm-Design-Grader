#include <bits/stdc++.h>
using namespace std;

int n,k;

void ss(vector<int> &v,int start,int stop){
    if (k<=1) return;
    if (stop-start ==1) return;

    int mid = ((start+stop) /2);
    swap(v[mid-1],v[mid]);
    k-=2;
    ss(v,start,mid);
    ss(v,mid,stop);
}


int main(){
    cin >> n >> k;
    vector<int> v;
    for (int i=1;i<= n; i++) v.push_back(i);
    if (k%2==0 || k> 2 * n - 1) cout << -1;
    else{
        ss(v,0,n);
        for (auto i:v) cout << i << " ";
    }
}