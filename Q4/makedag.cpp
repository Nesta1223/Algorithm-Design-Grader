#include <bits/stdc++.h>
using namespace std;
vector<int> g[200005];
vector<int> gr[200005]; 
map<pair<int,int> , int> direct;
vector<pair<int,int>> order;
int visited[200005];

int main(){
    int  n , e; cin >> n >> e;
    for (int i=1 ; i<=e ;i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
        direct[make_pair(a,b)] = -1;
        order.push_back(make_pair(a,b));
    }
    // check connnected component later
    for (int j=1 ; j<= n ;j++){
        if (!visited[j]){
            queue<int> q;
            q.push(j);
            visited[j] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for (auto i: g[node]){
                    //node to i
                    pair<int,int> p = make_pair(node, i);
                    if (direct[p] == -1){
                        direct[p] = 0;
                        q.push(i);

                    }
        
                }
                for (auto i: gr[node]){
                    //node to i
                    pair<int,int> p = make_pair(i, node);
                    if (direct[p] == -1){
                        direct[p] = 1;
                        q.push(i);

                    }
                
        
                }
        
            }

        }
    }
    // if (direct.size() != e) cout << "eiei";
    for (auto i : order){
        cout << direct[i] << " ";
    }
}