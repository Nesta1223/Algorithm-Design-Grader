#include <bits/stdc++.h>
using namespace std;



pair<int,int> go[4] = {{0,1},{0,-1} , {1,0} ,{-1,0}};// right left up down

map<int,pair<int,int>> origin;

struct state{
    pair<int,int> zpos = {0,0};
    int time=0;
    int l1dis=0;
    int lastgo =-1;
    // map<int,pair<int,int>> store;
    int grid[5][5];
    bool operator< (const state &s) const{
        if (this->l1dis + this->time == s.l1dis + s.time){
            return this->l1dis > s.l1dis;
        }
        else if (this->l1dis == s.l1dis){
            return this->time > s.time;
        }
        return this->l1dis + this->time > s.l1dis + s.time;
    }
    
};

int calpenalty(int a, int posx ,int posy){
    return abs(posx- origin[a].first) + abs(posy -origin[a].second);
    
}

int main(){
    for (int i=0;i<=15;i++){
        if (i==0) {
            origin[i] = make_pair(4,4);
            continue;
        }
    
        int a = i/4;
        int b = i%4;
        a++;
        if (b==0) {
            b = 4;
            a--;
        }
        origin[i] = make_pair(a,b);
    }

    
    state s0;
    for (int i=1;i<= 4;i++){
        for (int j=1;j<=4;j++){
            int a;
            cin >> a;
            s0.grid[i][j] = a;
            if (a==0) s0.zpos = make_pair(i,j);
            s0.l1dis += calpenalty(a,i,j);
        }
    }


    // for (int i=1;i<=4;i++){
    //     for (int j=1;j<=4;j++){
    //         cout << s0.grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i=0;i<16;i++){
    //     cout << s0.store[i].first << ',' << s0.store[i].second << endl;
    // }

    // cout << s0.l1dis;




    priority_queue<state> pq;
    pq.push(s0);
    int ans;
    // int cnt = 5;
    while(!pq.empty() ){
        // cnt--;
        state s = pq.top();
        pq.pop();
        if (s.l1dis == 0) {
            ans = s.time;
            break;
        }
        for (int i=0;i<4;i++){
            state s1 = s;
            if ( (s1.lastgo == 0  && i==1) ||
                (s1.lastgo == 1  && i==0) ||
                (s1.lastgo == 2  && i==3) ||
                (s1.lastgo == 3  && i==2) 
            
            )  continue;


            int x = s1.zpos.first;
            int y = s1.zpos.second;

            int gox = x+ go[i].first;
            int goy = y+ go[i].second;
            // cout << "eiei" << x << ' ' << y  << endl;

            if (gox >= 1 && goy >=1 && gox <=4 && goy <=4){
                int value  = s1.grid[gox][goy];
                s1.l1dis -= calpenalty(0,x,y) + calpenalty(value , gox, goy);
                swap(s1.grid[gox][goy],s1.grid[x][y]);
                s1.l1dis += calpenalty(0,gox,goy) + calpenalty(value , x, y);
                s1.time++;
                s1.zpos = {gox,goy};
                s1.lastgo = i;
                pq.push(s1);
                // cout << value << endl;
            }
        }

    }
    cout << ans;
}