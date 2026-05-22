#include <bits/stdc++.h>
using namespace std;


void recur (vector<vector<int>> &v, int a ,int b,int row,int col){
    if (a==0){
        v[row][col] = b;
        return;
    } 
    int x = pow(2,a-1);
    recur(v,a-1,b,row,col);
    recur(v,a-1,b-1,row,col+x);
    recur(v,a-1,b+1,row+x,col);
    recur(v,a-1,b,row+x,col+x);

}

int main(){
    int a,b; cin >> a >> b;
    int size = pow(2,a);
    vector<vector<int>> v(size+1, vector<int>(size+1));
    recur(v,a,b,1,1);
    for (int i=1;i<=size;i++){
        for (int j=1;j<=size;j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

}