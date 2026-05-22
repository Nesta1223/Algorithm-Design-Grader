#include <bits/stdc++.h>
using namespace std;

vector<int> g[105];

struct state
{
    string rooms;
    int empty;
    int correct;
    int last ;
    vector<int> moves;
    bool operator< (const state &s) const{
        return correct < s.correct;
    }
};


int main(){
    int n,m; cin >> n >>m;//2n+1
    for (int i=1;i<=m;i++){
        int a,b; cin >> a >> b;  
        g[a].push_back(b);      
        g[b].push_back(a);   
    }
    // cout << -1;
    string goal = "0";
    string color = "0";
    for (int i=1 ; i<= n;i++){
        color+= "R";
        goal += "B";
    }
    for (int i=n+1 ;i<=2*n;i++){
        color += "B";
        goal+="R";
    }
    goal+="0";
    color+="0";
    // cout << color << ' ' << goal << endl;
    int N = 2*n+1;
    state start;
    start.rooms = color;
    start.empty = 2*n+1;
    start.correct =0;
    start.last = -1;
    // start.moves.push_back(2*n+1);                                                               


    vector<int> ans;
    set<string> seen;
    seen.insert(color);
    int cnt =0;
    priority_queue<state> pq;
    pq.push(start);
    bool found = false;
    bool exceed = false;
    while(!pq.empty() && !found){
        // cout << cnt << "\n";
        state cur = pq.top(); pq.pop();
        if(cnt >20000){
            exceed = true;
            break;
        }
        cnt++;
        if (cur.rooms == goal){
            ans = cur.moves;                                                        
            found = true;
            break;
        }
        int emp = cur.empty;
        for (auto node: g[cur.empty]){
            if (node == cur.last) continue;
            state nxt = cur;
            nxt.correct = cur.correct;
            if ( 1<= cur.empty && cur.empty <=n &&  n+1 <= node && node <= 2*n ){
                if (nxt.rooms[node] == 'R') nxt.correct--;
                else nxt.correct++;
            }
            else if ( 1<= node && node <=n &&  n+1 <= cur.empty && cur.empty <= 2*n ){
                if (nxt.rooms[node] == 'B') nxt.correct--;
                else nxt.correct++;
            }
            swap(nxt.rooms[node] ,nxt.rooms[cur.empty]);
            nxt.empty = node;
            nxt.moves.push_back(node);
            nxt.last = cur.empty;
            
            if (seen.find(nxt.rooms) != seen.end()) continue;
            // cout << "eiei";
            seen.insert(nxt.rooms);
            pq.push(nxt);
        }



    }                                                           

    if (exceed || ans.size() ==0) cout << -1 << '\n';
    else{
        cout << ans.size() << '\n';
        for (auto i:ans) cout << i << " ";
        cout << '\n';
    }




    

}