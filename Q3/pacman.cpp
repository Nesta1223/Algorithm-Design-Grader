#include <bits/stdc++.h>
using namespace std;
int tghost[105];
pair<int,int> sghost[105];
int grid[105][105];// 0 = empty , 1 = wall, 2 = ghost 
int visited[105][105];
pair<int,int> go[4] = {{0,1},{0,-1},{1,0},{-1,0}};

int main(){
    int k ; cin >>k;
    while(k--){
        int r,c,n,time,rp,cp;
        cin >> r >> c >> n >> time >> rp >> cp;
        rp++;
        cp++;
        for (int i=1;i<=n;i++){
            cin >> tghost[i];
            int a,b ; cin >> a >> b;
            sghost[i] = make_pair(a+1,b+1);
        }
        memset(grid,-1,sizeof grid);
        for (int i=1;i<=r;i++){
            for (int j=1;j<=c;j++){
                char x; cin >> x;
                if (x=='.') grid[i][j] = 0;
                else if (x=='#') grid[i][j] = 1;
            }
        }
        //go for all ghost
        for (int i=1;i<=n;i++){
            memset(visited,0 , sizeof visited);
            int x0 = sghost[i].first;
            int y0 = sghost[i].second;
            int t0 = time - tghost[i];
            queue<pair<int,int>> q;
            q.push({x0,y0});
            queue<int> qtime;
            qtime.push(t0);
            grid[x0][y0] = 2;
            visited[x0][y0] = 1;
            while(!q.empty()){
                int x1 = q.front().first;
                int y1 = q.front().second;
                int t  = qtime.front();
                if (t<=0) break;
                q.pop();
                qtime.pop();
                for (int j=0;j<4;j++){
                    int x2 = x1+go[j].first;
                    int y2 = y1+go[j].second;
                    if (!visited[x2][y2] && grid[x2][y2] != 1 && grid[x2][y2] !=-1){
                        q.push(make_pair(x2,y2));
                        qtime.push(t-1);
                        grid[x2][y2] = 2;
                        visited[x2][y2] = 1;
                    }

                }
                
            }
            
        }
        // for (int i=1;i<=r;i++){
        //     for (int j=1;j<=c;j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        //go for pacman
        memset(visited, 0 ,sizeof visited);
        queue<pair<int,int>> pac;
        queue<int> qtime;
        pac.push(make_pair(rp,cp));
        qtime.push(time);
        visited[rp][cp] = 1;
        bool cando = false;
        if (grid[rp][cp] ==0) cando = true;
        while(!pac.empty() && !cando){
            int x0 = pac.front().first;
            int y0 = pac.front().second;
            int tt = qtime.front();
            if (tt<=0) break;
            pac.pop();
            qtime.pop();
            for (int j=0 ; j<4;j++){
                int x1 = x0+ go[j].first;
                int y1 = y0 + go[j].second;
                if ( grid[x1][y1] == 0 ){
                    cando = true;
                    break;
                }
                if (!visited[x1][y1] && grid[x1][y1]==2 ){
                    pac.push(make_pair(x1,y1));
                    qtime.push(tt-1);
                    visited[x1][y1] = 1;
                }


            }

        }
        if (cando) cout << "YES" << '\n';
        else cout << "NO" << '\n';

        
    }
}