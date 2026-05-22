#include <bits/stdc++.h>
using namespace std;

int a[7000] ;

int main(){
    int n,m ; cin >> n >> m;
    for (int i=1;i<= n;i++) cin >> a[i];
    for (int j=0;j< m;j++){
        int ans; cin >> ans;
        bool yes = false;
        for (int i=1;i<= n;i++) {
            int p1 = i;
            int p2= i+1;
            int p3 = n;
            while(p2< p3){
                if ( a[p1] + a[p2] + a[p3] < ans) p2++;
                else if (a[p1] + a[p2] + a[p3] > ans) p3--;
                else {
                    yes = true ;
                    break;
                }
            }
            if (yes) break;

        }
        if (yes) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}