#include <bits/stdc++.h>
using namespace std;

string sol[1000000];
int used[1000000];
string letter[1000000];
set<string> ans;
set<pair<char,char>> forbid;
int rec[3];


void combi(string y,int len,int counta,int countb,int countc,int n,char prev){
    if (n==len) {
        // cout << y << "a";
        ans.insert(y);
        return;
    }
    string A = y+ "A";
    string B = y+ "B";
    string C = y+ "C";
    if (counta +1 <= rec[0] && forbid.find(make_pair(prev,'A')) == forbid.end())  combi(A,len+1,counta+1,countb,countc,n,'A');
    if (countb +1 <= rec[1] && forbid.find(make_pair(prev,'B')) == forbid.end()) combi(B,len+1,counta,countb+1,countc,n,'B');
    if (countc +1 <= rec[2] && forbid.find(make_pair(prev,'C')) == forbid.end()) combi(C,len+1,counta,countb,countc+1,n,'C');

}

int main(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    cin >> rec[0] >> rec[1] >> rec[2];
    int m; cin >> m;
    
    for (int i=0;i<m;i++){
        string x; cin >> x;
        forbid.insert(make_pair(x[0],x[1]));
    }
    string y = "";
    combi(y,0,0,0,0,n,' ');
    cout << ans.size() << "\n";
    for (auto i:ans) cout << i << "\n";


}