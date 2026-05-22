#include <bits/stdc++.h>
using namespace std;
string dp[505][505];
int mark[505][505];


string lcs (string a , string b){
    if (a == "" || b == "") {
        dp[a.size()][b.size()] = "";
        mark[a.size()][b.size()] = 1;
        return "";
    }
    if (mark[a.size()][b.size()] == 1) return dp[a.size()][b.size()];
    string c = a;
    string d = b;
    c.pop_back();
    d.pop_back();
    if (a[a.size()-1] == b[b.size()-1])  {
        dp[a.size()][b.size()] =  lcs(c,d) + a[a.size()-1] ;
        mark[a.size()][b.size()] = 1;
        return dp[a.size()][b.size()];
    }
    string e = lcs(a,d);
    string f = lcs(c,b);
    if (e.size() >= f.size() ){
        dp[a.size()][b.size()] = e;
    }
    else {
        dp[a.size()][b.size()] = f;
    }
    mark[a.size()][b.size()] = 1;
    return dp[a.size()][b.size()];
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    string a,b ; cin >> a >> b;
    lcs(a,b);
    cout << dp[a.size()][b.size()];
    cout << dp[a.size()][b.size()].size();

}