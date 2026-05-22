#include <bits/stdc++.h>
using namespace std;

int sol[100000];
vector<int> stu[21];
bool cover[1001];

void combi(int n,int len,int &loww,int day,int &cnt){
    if (cnt >= loww) return;
    if (len <= n){
        sol[len] = 1;
        int k = cnt+1;
        combi(n,len+1,loww,day,k);
        
        sol[len] =0;
        combi(n,len+1,loww,day,cnt);

    }
    else{
        vector<int> ans;
        for (int i=1;i<=n;i++){
            if (sol[i] == 1) {
                // cout << i << " ";
                ans.push_back(i);
            }
        }
        // cout << endl;
        int x= 0;
        bool full = false;
        for (auto i : ans){
            for (auto j: stu[i]){
                if (cover[j] == false){
                    cover[j] = true;
                    x++;
                    if (x== day){
                        full = true;
                        break;
                    }
                 }
            if (full ) break;
        }}
        // cout << endl;

        // cout << x << " ";
        int y = ans.size();
        if(x== day)loww = min(loww,y);
        for (int i=0;i<1001;i++) cover[i] = false;


    }
}


int main(){
    int day , m; cin >> day >> m;
    for (int i=1;i<=m;i++){
        int x ; cin >> x;
        for (int j=0;j<x;j++){
            int a; cin >> a;
            stu[i].push_back(a);
        }
    }
    // for (int i=1;i<=m;i++){
    //     cout << "stu" << i <<":";
    //     for (auto j: stu[i]) cout << j << " ";
    // }
    // cout << endl;
    
    int x = 21;
    int cnt = 0;
    combi(m,1,x,day,cnt);
    cout << x;
}