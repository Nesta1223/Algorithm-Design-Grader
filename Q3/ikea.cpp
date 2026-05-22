#include <bits/stdc++.h>
using namespace std;

vector<int> g[1005];
int in[1005];
int orin[1005];
int dis[1005];
int arr[1005];
int main(){
    int n,e ; cin >> n >> e;
    for (int i=1; i<=e;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        in[b]++;
        orin[b]++;
    }

    // for (int i=1;i<=n;i++) cout << in[i] << " ";

    for (int i=1;i<=5;i++){
        memset(arr,0,sizeof arr);
        bool cor = true;
        for (int j = 1;j<=n;j++){
            in[j] = orin[j];
        }


        for (int j = 1;j<=n;j++) cin >> arr[j];
        for (int j = 1; j<= n;j++){
            int cnt = arr[j];
            if (in[cnt]> 0) {
                cor = false;
                break;
            }
            for (auto k : g[cnt] ){
                in[k]--;
            }
        }

        if (cor ) cout << "SUCCESS" << '\n';
        else cout << "FAIL" << '\n';
    }
    


}