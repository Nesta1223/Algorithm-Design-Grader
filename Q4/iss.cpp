#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll cnt = 0;
void recur(int left,int n, int lowest){
    if(left ==0) {
        cnt++;
        return;
    }
    for (int i=lowest;i<=left;i++){
        recur(left-i,n,i);
    }
}




int main(){
    int n; cin >> n;
    recur(n,n,1);
    cout << cnt;
}
