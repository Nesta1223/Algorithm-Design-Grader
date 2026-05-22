//mark variable count all connected component instead of counting only the loop , how to solve it?
#include <bits/stdc++.h>
using namespace std;

int grid[1005][1005];
int visited[1005][1005];
int depth[1005][1005];


using pi = pair<int,int>;
int loop = 0;
int longest =  0;
int flag = 0;


void dfs(pi start,pi parent,int mark){
    // if (flag==1) return;
    int a = start.first;
    int b = start.second;
    // visited[a][b] = mark;
    // depth[a][b] = dis;
    //up 2 3 6 

    if ( (grid[a][b] == 2 || grid[a][b] == 3 || grid[a][b] == 6)
         &&    (grid[a-1][b] == 2 || grid[a-1][b] == 4  || grid[a-1][b] == 5 )
         ){
            if (!visited[a-1][b]){
                depth[a-1][b] = depth[a][b]+1;
                visited[a-1][b] = mark;
                dfs({a-1,b},start,mark);
            }
            else if (make_pair(a-1,b) != parent){
                flag = 1;
                int cycle = depth[a][b] - depth[a-1][b] +1;
                longest = max(longest, cycle);
                // return;
            }


    }
    //down 2 4 5
    if ( (grid[a][b] == 2 || grid[a][b] == 4 || grid[a][b] == 5)
         &&    (grid[a+1][b] == 2 || grid[a+1][b] == 3  || grid[a+1][b] == 6 ) 
         ){
            if (!visited[a+1][b]){
                depth[a+1][b] = depth[a][b]+1;
                visited[a+1][b] = mark;
                dfs({a+1,b},start,mark);
            }
            else if (make_pair(a+1,b) != parent){
                flag = 1;

                int cycle = depth[a][b] - depth[a+1][b] +1;
                longest = max(longest, cycle);
                // return;
            }


    }

    //left 1 5 6
    if ( (grid[a][b] == 1 || grid[a][b] == 5 || grid[a][b] == 6)
         &&    (grid[a][b-1] == 1 || grid[a][b-1] == 3  || grid[a][b-1] == 4  )
       ){
        if (!visited[a][b-1]){
                depth[a][b-1] = depth[a][b]+1;
                visited[a][b-1] = mark;
                dfs({a,b-1},start,mark);
            }
        else if (make_pair(a,b-1) != parent){
                flag = 1;
                int cycle = depth[a][b] - depth[a][b-1] +1;
                longest = max(longest, cycle);
                // return;
            }


    }

    //right 1 3 4
    if ( (grid[a][b] == 1 || grid[a][b] == 3 || grid[a][b] == 4)
         &&   ( grid[a][b+1] == 1 || grid[a][b+1] == 5  || grid[a][b+1] == 6  )
       ){
        // cout << "yay";
        if (!visited[a][b+1]){
                depth[a][b+1] = depth[a][b]+1;
                visited[a][b+1] = mark;
                dfs({a,b+1},start,mark);
            }
        else if (make_pair(a,b+1) != parent){
                flag = 1;
                int cycle = depth[a][b] - depth[a][b+1] +1;
                longest = max(longest, cycle);
                // return;
            }


    }

}

int main(){
    int r,c ; cin >> r >> c;
    for (int i=1;i<=r;i++){
        for (int j =1 ; j<=c ; j++){
            cin >> grid[i][j];
        }
    }
    int mark = 1;
    for (int i=1;i<=r;i++){
        for (int j =1 ; j<=c ; j++){
            if (!visited[i][j] ){
                depth[i][j] = 1;
                dfs(make_pair(i,j), make_pair(0,0),mark);
                // cout << i << " " << j << "->" << mark << endl;
                if (flag == 1){
                    flag = 0;


                        // cout << "round " << mark << endl;
                        // for (int a = 1;a<=r;a++){
                        //     for (int b=1 ; b<=c;b++){
                        //         cout << visited[a][b] << " ";
                        //     }
                        //     cout << endl;
                        // }
                    mark++;
                }
            }     
        }
    }
    // for (int i=1;i<=r;i++){
    //     for (int j =1 ; j<=c ; j++){
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    cout << mark-1 << " " << longest ;


}