#include <bits/stdc++.h>
using namespace std;
int a[505];


void combi(int now,int p,int n){
    if(now == 0 ){
        int count = 0;
        for(int i=1;i<=n;i++)
            if (a[i] == 1) count++; 
        if (count==p) {
            for (int i=1;i<=n;i++){
                cout << a[i];
            }
            cout <<"\n";
        }
        return;
    }

    a[now]  = 1 ;
    combi(now-1,p,n);
    a[now]  = 0;
    combi(now-1,p,n);
}
int main(){
    int n,p;
    cin>>p>>n;
    combi(n,p,n);

}
//1 2 3 4 6 8
//