#include <bits/stdc++.h>
using namespace std;


void perm(int n,vector<int> &sol,int len,vector<bool> &used ){
    if (len<n){
        for (int i=1;i<=n;i++){
            if (used[i] == false){
                used[i] = true;
                sol[len]= i;
                perm(n,sol,len+1,used);
                used[i] = false;
            }
        }
    }
    else{
        for (auto x :sol) cout<< x << " ";
        cout << endl;
        return;
    }
}

void combi(int n , vector<int> &sol, int len){
    if (len<n){
        sol[len] = 0;
        combi(n,sol,len+1);
        sol[len] = 1;
        combi(n,sol,len+1);
    }
    else{
        for (int i=0;i<n;i++){
            if (true){
                cout<< sol[i]<< " ";
            }
        }
        cout << "." << endl;
    }
}

int main(){
    int n=3;
    vector<int> sol(n);
    vector<bool> used(n+1);
    perm(n,sol,0,used);
    // combi(n,sol,0);
}