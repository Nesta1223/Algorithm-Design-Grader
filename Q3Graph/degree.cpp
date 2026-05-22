#include <bits/stdc++.h>
using namespace std;

int graph[5005][5005];
int num[100005];

int main(){
    int n; cin >> n;
    int maxx = 0;
    for (int i=1 ;i<=n;i++){
        int cnt = 0;
        for (int j=1;j<=n;j++){
            int x ; cin >> x;
            if (x==1) cnt++;
        }
        num[cnt]++;
        maxx = max(maxx, cnt);
    }

    for (int i=0 ; i<= maxx;i++)
    cout << num[i] << " ";
}