#include <bits/stdc++.h>
using namespace std;

bool check(string s){
    if (s.size() == 2) return true;
    string s1 = s.substr(0,s.size()/2);
    string s2 = s.substr(s.size()/2,s.size()/2);
    int count1 = 0;
    int count2 =0;
    for (int i=0;i<s.size()/2;i++){
        if (s1[i] == '1') count1++;
        if (s2[i] == '1' ) count2++;
    }
    if (abs(count1-count2) >1) return false;
    else return check(s1) && check(s2);
}


int main(){
    int n,k;
    cin >> n >> k;
    for (int i=0;i<n;i++){
        string s;
        for (int j=0;j<pow(2,k);j++){
            char c; cin >> c;
            s+=c;
        }
        bool yes =check(s);
        if (yes) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}