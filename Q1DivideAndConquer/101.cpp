#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void genBit(string &s,ll n,int state, ll &count){
    if (n==0) {
        if(state!=4) count++;
        return;
    }
    if(state == 1){
        s+="0";
        genBit(s,n-1,1,count);
        s.pop_back();
        s+="1";
        genBit(s,n-1,2,count);
        s.pop_back();        
    }
    else if(state == 2){
        s+="0";
        genBit(s,n-1,3,count);
        s.pop_back();
        s+="1";
        genBit(s,n-1,2,count);
        s.pop_back();        
    }
    else if(state == 3){
        s+="0";
        genBit(s,n-1,1,count);
        s.pop_back();
        s+="1";
        genBit(s,n-1,4,count);
        s.pop_back();        
    }
    else if(state == 4){    
        return;
    }
}

int main(){
    int n; cin >> n;
    string s= "";
    ll count =0;
    genBit(s,n,1,count);
    cout << count;
}