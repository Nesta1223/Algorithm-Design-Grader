#include <bits/stdc++.h>
using namespace std;

int r[100001];



int cut(int n, int a ,int b , int c){
    if (n<0 ) return INT_MIN;
    if (n==0) {
        return 0;
    }
    // if (n==a || n==b || n==c) return 1;
    if (r[n] != -1 ) return r[n];
    int x= cut(n-a,a,b,c);
    int y = cut(n-b,a,b,c);
    int z = cut(n-c,a,b,c);
    int ans = max({x+1,y+1,z+1});//the last code is invalid
    if (ans <0) r[n] = INT_MIN;//max(-1,INT_MIN) = -1; where -1 mean havent touch yet, INT_MIN mean impossible 
    else r[n] = ans;
    return r[n];
}

int main(){
    int n,a,b,c ; cin >> n >> a >> b >> c;
    for (int i=0;i<100001;i++){
        r[i] = -1;  
    }
    r[0] = 0;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(),v.end());
    a = v[0];
    b = v[1];
    c = v[2];
    if (b%a == 0) b=a;
    if (c%a == 0) c =a;
    if (c%b == 0) c=b;
    // r[a] = 1;
    // r[b] =1;
    // r[c] = 1;
    int x = cut(n,a,b,c);
    cout << r[n];
    

}