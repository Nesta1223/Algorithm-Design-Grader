#include <bits/stdc++.h>
using namespace std;

// int a[100000];
// int v[10000000];
// void genBit(int now,int n){
//     if (now > n) {
//         for (int i=1;i<=n;i++){
//             cout << a[i];
//         }
//         cout << endl;
//         return;
//     }
//     a[now] = 0;
//     genBit(now+1,n);
//     a[now] = 1;
//     genBit(now+1,n);

// }


bool check(string s, int k){
    if (k==1) return s=="01";
    string s1 = s.substr(0,pow(2,k-1));
    string s2 = s.substr(pow(2,k-1),pow(2,k-1));
    string s3 = s1;
    reverse(s3.begin(),s3.end());
    return (check(s1,k-1) || check(s3,k-1)  ) && check(s2,k-1);
}
int main(){
    int n,k; cin >> n >>k ;
    while(n--) {
        string s;
        for (int i=0;i< pow(2,k) ;i++){
            char a; cin >> a;
            s+=a;
        }
        bool c = check(s,k);
        if (c) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}