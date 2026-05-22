#include <bits/stdc++.h>
using namespace std;


int grid[5005][5005];
int visited[5005][5005];
pair<int,int> go[4] = {{0,1} ,{0,-1} ,{1,0} , {-1 ,0}};

struct state
{
    int x;
    int y;
    int cnt;

};


int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int r , c; cin >> r >> c;
    int one =0;
    int two =0;
    for (int i=1 ; i<= r; i++){
        for (int j=1 ; j<=c ; j++){
            cin >> grid[i][j];
            if (grid[i][j] == 1)one++;
            else if (grid[i][j] ==2) two++;
        }
    }
    //start from 1
    queue<state> q;
    for (int i=1 ; i<= r; i++){
        for (int j=1 ; j<=c ; j++){
            if ( grid[i][j] == 1){
                state s;
                s.x = i;
                s.y = j;
                s.cnt = 1;
                q.push(s);
                visited[i][j] = 1;
            }
        }
    }
    int ans ;
    while(!q.empty()){
        state s1= q.front();
        q.pop();
        if (grid[s1.x][s1.y] == 2){
            ans = s1.cnt;
            cout << ans ; 
            break;
        }
        for (int i=0;i<4;i++){
            int x = s1.x + go[i].first;
            int y = s1.y + go[i].second;
            state s2= s1;
            s2.x = x;
            s2.y = y;
            s2.cnt++;
            if ( x>=1 && y>=1 && x<=r && y<=c  &&  !visited[x][y]  && grid[x][y] !=3 ){
                visited[x][y] = 1;
                q.push(s2);
            }
        }



}
}