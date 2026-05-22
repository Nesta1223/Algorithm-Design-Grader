#include <bits/stdc++.h>
using namespace std;

bool used[22] ;
int sol[22];
int Prev[22];

void permu(int n,int now){
    if (now>=n){
        for (int i=0;i<n;i++){
            cout << sol[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i=0;i<n;i++){
        if (used[i] || !used[Prev[i]]) continue;
        used[i] = true;
        sol[now] = i;
        permu(n,now+1);
        used[i] = false;

    }


}

int main(){
    int n,m; cin >> n >> m;
    for (int i=0;i<n;i++) Prev[i] = 21;
    used[21] = true;
    for (int i=0;i<m;i++){
        int k1 ,k2 ; cin >> k1 >> k2;
        Prev[k2] = k1;
    }
    permu(n,0);
}