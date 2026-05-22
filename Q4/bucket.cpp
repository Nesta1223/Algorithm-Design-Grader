queue<state> pq;
    for (int i=1 ; i<= r; i++){
        for (int j=1 ; j<=c ; j++){
            if (grid[i][j] == 1){
                state s;
                s.present.first = i;
                s.present.second = j;
                s.cnt = 1;
                pq.push(s);
            }
        }
    }
    int ans ;
    while (!pq.empty()){
        state s0 = pq.front();
        pq.pop();
        if (grid[s0.present.first][s0.present.second] == 2) {
            ans = s0.cnt;
            break;
        }

        for (int i=0;i<4 ; i++){
            state s1 = s0;
            s1.last.first = s1.present.first;
            s1.last.second = s1.present.second;
            s1.present.first += go[i].first;
            s1.present.second += go[i].second;
            s1.cnt++;
            if (s1.present.first >= 1 && s1.present.first <= r 
                && s1.present.second >=1 && s1.present.second<=c
               && grid[s1.present.first][s1.present.second] != 3 && grid[s1.present.first][s1.present.second] != 1
            && !(s1.present.first != s1.last.first && s1.present.second != s1.last.second)){
                pq.push(s1);
            }
        }
    }
    cout << ans;