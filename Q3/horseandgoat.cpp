#include <bits/stdc++.h>
using namespace std;

int grid[4005][4005];
int timmy[4005][4005];
int rocket[4005][4005];
int rows[4005];
int cols[4005];
pair<int,int> go[4] = { {1,0}, {-1,0} ,{0,1} ,{0,-1}};

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    memset(timmy,127, sizeof timmy);
    int r,c; cin >> r >> c;
    pair<int,int> start;
    pair<int,int> goal;
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            char x ; cin >> x;
            if (x== 'S'){
                start = {i,j};
                grid[i][j] = 1;
            } 
            else if (x== 'T') {
                goal = {i,j};
                grid[i][j] =1;
            }
            else if (x=='X') grid[i][j] = 0;
            else if (x=='#') {
                grid[i][j] = 1;
                rocket[i][j] = 1;
            }
            else grid[i][j] = 1;//0 = cant go , 1 = not go yet , 2  = went
        }
    }


    // for (int i=1;i<=r;i++){
    //     for (int j=1;j<=c;j++){
    //         cout << rocket[i][j] << " ";
    //     }
    //     cout << endl;
    // }






    queue<pair<int,int>> q;
    queue<int> time;
    q.push(start);
    time.push(0);
    timmy[start.first][start.second] = 0;


    while(!q.empty() && timmy[goal.first][goal.second] > 1e9){
        // cout << "eiie";
        int x = q.front().first;
        int y = q.front().second;
        int t = time.front();
        // cout << x << " " << y << endl;
        q.pop();
        time.pop();
        // if ( t > timmy[x][y]) continue;
        if (rocket[x][y]) {
            // cout << rows[x] << " " << cols[y] << endl;
            for (int i=0;i<4;i++){
                // if (i==1 || i==3) continue;
                if ((i==0 || i==1)  && !cols[y]     ){//fix col do row
                    // cout << "eiei" << endl;
                    // cout << t << endl;
                    int x1 = x;
                    int y1 = y;
                    // cout << x1 << " " << y1 << endl;
                    while(x1 >0 && y1 >0 && x1 <=r && y1<=c){
                        // if (x1==4) cout << "eiei";
                        x1 += go[i].first;
                        y1 += go[i].second;
                        if (timmy[x1][y1] > t+1 && grid[x1][y1] == 1){
                            // cout << "eiei" << " ";
                            // cout << t << endl;
                            timmy[x1][y1] = t+1;
                            q.push({x1,y1});
                            time.push(t+1);
                        }
                    }

                }
                else if ((i==2 || i==3) && !rows[x] ){
                    int x1 = x;
                    int y1 = y;
                    while(x1 >0 && y1 >0 && x1 <=r && y1<=c){
                        x1 += go[i].first;
                        y1 += go[i].second;
                        if (timmy[x1][y1] > t+1 && grid[x1][y1] == 1){
                            // cout << "eiei" << " ";
                            // cout << t << endl;
                            timmy[x1][y1] = t+1;
                            q.push({x1,y1});
                            time.push(t+1);
                        }
                    }
                }
            }
            rows[x] = 1;
            cols[y] = 1;
        }
        else{
            for (int i=0;i<4;i++){
                int x1 = x+go[i].first;
                int y1 = y+go[i].second;
                if (timmy[x1][y1] > t+1 && grid[x1][y1] == 1){
                    q.push({x1,y1});
                    time.push(t+1);
                    timmy[x1][y1]= t+1;
                    // if (goal == make_pair(x1,y1)) ans = t+1;
                }
            }

        }



    }

    // for (int i=1;i<=r;i++) cout << cols[i] << " ";
    // cout << endl;

    // for (int i=1;i<=r;i++){
    //     for (int j=1;j<=c;j++){
    //         cout << timmy[i][j] << " ";
    //     }
    //     cout << endl;
    // }



    cout << timmy[goal.first][goal.second];
}