#include <bits/stdc++.h>
using namespace std;
int a[30];

void genBit(int now , int n, int p,vector<string> &ans){
    if(now == n+1){
        string anss = "";
        int count = 0;
        for (int i =1;i<=n;i++){
            anss += to_string(a[i]);
            if (a[i] == 1) count++;
            else if (a[i] == 0 && count <p)count=0;
            // cout << a[i];
        }
        // cout << anss << endl;
        if(count >=p)ans.push_back(anss);
        return;
    }
    a[now] = 0;
    genBit(now+1,n,p,ans);
    a[now] = 1;
    genBit(now+1,n,p,ans);
}

int main(){
    int n,p ; cin >> n >> p;
    vector<string> ans;
    genBit(1,n,p,ans);
    for(auto i: ans){
        cout << i << "\n";
    }
}