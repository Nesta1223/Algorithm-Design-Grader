#include <bits/stdc++.h>
using namespace std;

bool similar(string s1,string s2){
    if (s1 == s2) return true;
    if (s1.size() == 1 && s1!= s2) return false;
    string a1 = s1.substr(0,s1.size()/2);
    string a2 = s1.substr(s1.size()/2,s1.size()/2);
    string b1 = s2.substr(0,s2.size()/2);
    string b2 = s2.substr(s2.size()/2,s2.size()/2);
    return (similar(a1,b1) && similar(a2,b2)) || (similar(a1,b2) && similar(a2,b1));
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    bool x = similar(s1,s2);
    if (x) cout << "YES";
    else cout << "NO";
}