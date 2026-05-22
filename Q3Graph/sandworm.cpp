#include <bits/stdc++.h>
using namespace std;

int north[705][705];
int south[705][705];

pair<int,int> go[4] = {{1,0},{-1,0},{0,1},{0,-1}};


int main(){
    //ไปทุกหลุม ถ้าไปซ้ำไม่ต้องไป ถ้าที่ที่เหลือน้อยกว่าmax หยุดทำ
    int r,c,k; cin >> r >> c >> k;
    memset(north,-1,sizeof north);
    memset(south,-1,sizeof south);
    for (int i = 1 ; i<= r;i++){
        for (int j=1 ;j<= c ; j++){
            cin >> north[i][j];
        }
    }
    for (int i = 1 ; i<= r;i++){
        for (int j=1 ;j<= c ; j++){
            cin >> south[i][j];
        }
    }

    queue<pair<int,int>> q ;
    q.push(make_pair(1,1));
    int npoint = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        north[x][y] = 2;
        // cout << x << " " << y << endl;
        npoint++;
        for (int i=0; i<4;i++){
            int x1 = x+go[i].first;
            int y1 = y+go[i].second;
            if (north[x1][y1] ==  0) {
                north[x1][y1] = 2;
                q.push(make_pair(x1,y1));
            }
        }

    }
    // cout << npoint ;
    int maxs=0;
    vector<pair<int,int>> v;
    for (int i=1;i<=k;i++){
        int a, b ; cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    for(auto j:v){
        if (south[j.first][j.second] != 0 || !(north[j.first][j.second] ==0 || north[j.first][j.second] == 2)) continue;
        queue<pair<int,int>> qq;
        qq.push(j);
        int spoint = 0;
        while(!qq.empty()){
            int x = qq.front().first;
            int y = qq.front().second;
            qq.pop();
            south[x][y] = 2;
            // cout << x << " " << y << endl;
            spoint++;
            for (int i=0; i<4;i++){
                int x1 = x+go[i].first;
                int y1 = y+go[i].second;
                if (south[x1][y1] ==  0) {
                    south[x1][y1] = 2;
                    qq.push(make_pair(x1,y1));
                }
            }
        }
        maxs= max(maxs,spoint);



        // cout << "--------"<< j.first << " " << j.second << endl;
        // for (int a = 1 ; a<= r;a++){
        // for (int b=1 ;b<= c ; b++){
        //     cout << south[a][b] << " ";
        // }
        // cout << endl;
        // }
    }
    cout << npoint + maxs << " ";




    
}