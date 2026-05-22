#include <bits/stdc++.h>
using namespace std;
int score[55];
vector<int> g[55];
int quicksum[55];
int used[55];

int ans = 0;
int cucnt = 50;
void choose(int step, int n,int cnt,int sc){
    // if (sc + quicksum[n-step] < ans) return;
    if (step == n){
        // int sum = 0;
        int edge = 0;
        for (int i=1 ;i<= n;i++){
            if (used[i] ){
                // sum+= score[i];
                for (auto j : g[i]){
                    if (used[j]) edge++;
                }
            }
        }
        cucnt = min(cnt ,cucnt);
        if (edge == cnt *(cnt-1))ans = max(ans, sc);
        return;
    }   




    used[step+1] = 1;
    choose(step +1 , n,cnt +1, sc + score[step+1]);
    used[step+1] = 0;
    choose(step+1 , n,cnt,sc);
}



int main(){
    int n; cin >> n;
    multiset<int, greater<int>> s;
    for (int i=1; i<=n ; i++){
        cin >> score[i];
        s.insert(score[i]);
    } 
    for (int i=1 ; i<=n ; i++){
        for (int j = 1; j<= n ;j++){
            int x; cin >> x;
            if (x && i!=j){
                g[i].push_back(j);  
            }
        }
    }
    int total = 0;
    int cnt = 1;
    for (auto i: s){
        total+= i;
        quicksum[cnt] = total;
        cnt++;
    }


    choose(0 , n , 0,0);
    cout << ans;
}
    