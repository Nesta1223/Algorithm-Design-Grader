#include <bits/stdc++.h>
using namespace std;

int grid[6][6];
pair<int,int> shouldbe[20];

int l1dis(int x1,int y1 , int x2 ,int y2,int n){
    return min(abs(x1-x2), n- abs(x1-x2)) + min(abs(y1-y2), n- abs(y1-y2));
}

struct state{
    int n;
    vector<vector<int>> g;
    int penalty;
    int cnt;
    state(){
        vector<int> v(6,0);
        for (int i=0 ; i<6;i++){
            g.push_back(v);
        }
    }

    bool operator < (const state& s) const{
        return this->penalty > s.penalty;
    }
    vector<string> solute;
};

int main(){
    int n; cin>> n;
    for (int i=1 ; i<=n; i++){
        for (int j=1 ; j<= n; j++){
            cin >> grid[i][j];
        }
    }



    for (int i=1 ;i<= n*n;i++){
        shouldbe[i].second = i%n;
        shouldbe[i].first = i/n +1;
        if (shouldbe[i].second ==0) shouldbe[i].first--;
        if (shouldbe[i].second ==0) shouldbe[i].second=n;
        // cout << shouldbe[i].first << " " << shouldbe[i].second << endl;
    }

    state start;
    start.n = n;
    start.cnt=0;
    for (int i=1 ; i<=n; i++){
        for (int j=1 ; j<= n; j++){
            start.g[i][j] = grid[i][j];
            start.penalty += l1dis(i,j, shouldbe[grid[i][j]].first,shouldbe[grid[i][j]].second,n);
        }
    }
    priority_queue<state> pq;
    set<vector<vector<int>>> bucket;
    pq.push(start);
    bucket.insert(start.g);
    state ans;
    while(!pq.empty()){
        state s = pq.top();
        pq.pop();
        if (s.penalty== 0){
            ans = s;
            break;
        }
        int a = 1;
        for (int j=1 ; j<= n; j++){
            state s1 = s;
            int tmp = s1.g[j][1];
            for (int i=1 ; i<= n-1;i++){
                s1.g[j][i] = s1.g[j][i+1];
            }
            s1.g[j][n] = tmp;
            string x = to_string(j) + "L"; 
            s1.solute.push_back(x);
            s1.penalty = 0;
            for (int i=1 ; i<=n; i++){
                for (int j=1 ; j<= n; j++){
                    s1.penalty += l1dis(i,j, shouldbe[s1.g[i][j]].first,shouldbe[s1.g[i][j]].second,n);
                }
            }
            s1.cnt++;
            if(bucket.find(s1.g) == bucket.end() ){
                pq.push(s1);
                bucket.insert(s1.g);
            } 
        }
        //r
        for (int j=1 ; j<= n; j++){
            state s1 = s;
            int tmp = s1.g[j][n];
            for (int i=n ; i>= 2;i--){
                s1.g[j][i] = s1.g[j][i-1];
            }
            s1.g[j][1] = tmp;
            string x = to_string(j) + "R"; 
            s1.solute.push_back(x);
            s1.penalty = 0;
            for (int i=1 ; i<=n; i++){
                for (int j=1 ; j<= n; j++){
                    s1.penalty += l1dis(i,j, shouldbe[s1.g[i][j]].first,shouldbe[s1.g[i][j]].second,n);
                }
            }
            s1.cnt++;

            if(bucket.find(s1.g) == bucket.end()) {
                pq.push(s1);
                bucket.insert(s1.g);
            }
        }
        //u
        for (int j=1 ; j<= n; j++){
            state s1 = s;
            int tmp = s1.g[n][j];
            for (int i=n ; i>=2;i--){
                s1.g[i][j] = s1.g[i-1][j];
            }
            s1.g[1][j] = tmp;
            string x = to_string(j) + "D"; 
            s1.solute.push_back(x);
            s1.penalty = 0;
            for (int i=1 ; i<=n; i++){
                for (int j=1 ; j<= n; j++){
                    s1.penalty += l1dis(i,j, shouldbe[s1.g[i][j]].first,shouldbe[s1.g[i][j]].second,n);
                }
            }
            s1.cnt++;

            if(bucket.find(s1.g) == bucket.end()) {
                pq.push(s1);
                bucket.insert(s1.g);
            }
        }
        //d
        for (int j=1 ; j<= n; j++){
            state s1 = s;
            int tmp = s1.g[1][j];
            for (int i=1 ; i<= n-1;i++){
                s1.g[i][j] = s1.g[i+1][j];
            }
            s1.g[n][j] = tmp;
            string x = to_string(j) + "U"; 
            s1.solute.push_back(x);
            s1.penalty = 0;
            for (int i=1 ; i<=n; i++){
                for (int j=1 ; j<= n; j++){
                    s1.penalty += l1dis(i,j, shouldbe[s1.g[i][j]].first,shouldbe[s1.g[i][j]].second,n);
                }
            }
            s1.cnt++;

            if(bucket.find(s1.g) == bucket.end()){
                pq.push(s1);
                bucket.insert(s1.g);
            } 
        }
    }
    cout << ans.solute.size() << '\n';
    for (int i=0 ; i<ans.solute.size();i++){
        cout << ans.solute[i] <<'\n';
    }


}