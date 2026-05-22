#include <bits/stdc++.h>
using namespace std;

int city[505][505];
int infect[505][505];
int gox[4] = {1,-1,0,0};
int goy[4] = {0,0,1,-1};

int main(){
    memset(city,-1, sizeof city);
    int r,c , t;
    cin >> r >> c >> t;
    queue<int> day;
    queue<pair<int,int>> q;
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++) {
            cin >> city[i][j];
            if (city[i][j] == 1) {
                q.push(make_pair(i,j));
                day.push(1);
            }
        }
    }
    while(!q.empty()){
        int x1 = q.front().first;
        int y1 = q.front().second;
        q.pop();
        int d= day.front();
        day.pop();
        if (d> t) break;
        for (int i=0;i<4;i++){
            int idx = x1+gox[i];
            int idy =y1+ goy[i];
            if (city[idx][idy] == 0){
                city[idx][idy] = 1;
                q.push(make_pair(idx,idy));
                day.push(d+1);
            }
            
        }
    }
    int cnt  = 0;
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++) {
            if (city[i][j] == 1) cnt++;
        }
    }
    cout << cnt;


}