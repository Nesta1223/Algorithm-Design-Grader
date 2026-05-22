#include <bits/stdc++.h>
using namespace std;

int w[50][50];  
int score[50][50];
set<pair<int,int> , greater<pair<int,int>>> go[50];
int used[50];

int ans = -2e9;

void walk(int start , int step , int goal,int n, int point){
    if (point + score[start][goal] < ans ) return;
    if (step == n){
        ans = max(ans , point);
        return;
    }
    if (step == n-1){
        walk(goal , step+1 ,goal ,n , w[start][goal] + point );
    }
    else{
        for (auto i: go[start]){
            int weight = i.first;
            int node = i.second;
            if (node != start && node!= goal && !used[node]){
                used[node] = 1;
                walk(node , step+1 ,goal ,n , w[start][node] + point );
                used[node] = 0;
            }
        }

    }
}


int main(){
    memset(score, 0xcf , sizeof score);
    int n; cin >> n; 
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> w[i][j];
            score[i][j] = w[i][j];
            go[i].insert({w[i][j] , j});
        }
    }
    for (int i=1;i<=n;i++) score[i][i] = 0;


    for (int k = 1; k<=n;k++){
        for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=n ; j++){
                score[i][j] = max(score[i][j] , score[i][k] + score[k][j]);
            }
        }
    }
    used[1] = 1;//dont go to one
    walk(1 , 1 , n ,n , 0);

    cout << ans;



}