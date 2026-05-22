#include <bits/stdc++.h>
#
using namespace std;




int type(vector<vector<int>> v,int n,int row,int col,bool &valid){
    if (n==2){
        int one =0;
        int two =0;
        int three = 0;
        if (v[row+1][col+1]!=0) {
            valid = false;
            return 0;
        }

        map<int,int> m;
        m[v[row][col]]++;
        m[v[row+1][col]]++;
        m[v[row][col+1]]++;
        if (m.find(0)!= m.end() ) {
            return 0;
            valid = false;
        }
        for(auto i: m) {
            if (i.second >= 2 && i.first!=0) return i.first;
        }
        return 0;
    }
    else{
        int a = type(v,n/2,row,col,valid);
        int b = type(v,n/2,row+n/2,col,valid);
        int c = type(v,n/2,row,col+n/2,valid);
        // int d = 0;
        if (!valid) return 0;
        for (int i=n/2;i<n;i++){
            for (int j=n/2;j<n;j++){
                if (v[i][j] !=0 ) {
                    valid = false;
                    return 0;
                }
            }
        }
        // if (d!= 0) return 0;
        if (a==0 || b==0 || c==0) {
            valid = false;
            return 0;
        }

        map<int,int> m;
        m[a]++;
        m[b]++;
        m[c]++;
        for(auto i: m) {
            if (i.second >= 2 && i.first!=0) return i.first;
        }
        return 0;
    }
}


int main(){
    int n1; cin >> n1;
    bool valid1= true;
    vector<vector<int>> force1 (n1,vector<int>(n1));
    for (int i=0;i<n1;i++){
        for (int j=0;j<n1;j++){
            cin >> force1[i][j];
        }
    }
    int x1 = type(force1,n1,0,0,valid1);
    cout << x1 <<"\n";

    int n2; cin >> n2;
    bool valid2 = true;
    vector<vector<int>> force2 (n2,vector<int>(n2));
    for (int i=0;i<n2;i++){
        for (int j=0;j<n2;j++){
            cin >> force2[i][j];
        }
    }
    int x2 = type(force2,n2,0,0,valid2);
    cout << x2 <<"\n";

    int n3; cin >> n3;
    bool valid3 = true;
    vector<vector<int>> force3 (n3,vector<int>(n3));
    for (int i=0;i<n3;i++){
        for (int j=0;j<n3;j++){
            cin >> force3[i][j];
        }
    }
    int x3 = type(force3,n3,0,0,valid3);
    cout << x3 <<"\n";
    


}