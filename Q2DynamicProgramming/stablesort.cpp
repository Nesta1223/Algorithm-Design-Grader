#include <bits/stdc++.h>
using namespace std;

int arr[10005];

int main(){
    int n, m ; cin >> n >> m;
    vector<pair<int,int>> v;
    v.push_back({0,0});
    for (int i=1;i<=n;i++){
        pair<int,int> p;
        cin >> p.first;
        arr[i] = p.first;
        p.second = i;
        v.push_back(p);
    }
    // for (int i=1 ;i<=n;i++) cout << arr[i] << " " ;
    // cout << endl;

    sort(v.begin(),v.end());
    string val = "";
    string order = "";
    for (int i=1;i<=n;i++) {
        val += to_string(v[i].first);
        order += to_string(v[i].second);
    }
    // cout << val << endl;

    // for (int i=1 ; i<=n;i++) cout << v[i].second << " ";
    for (int j =1 ;j<=m;j++){
        string val2 = "";
        string order2 = "";
        for (int i=1 ; i<=n ; i++){
            int x ;
            cin >> x;
            // cout << x << endl;   
            val2 += to_string(arr[x]);
            order2+= to_string(x);
        }
        //  cout << val2 << endl;

        bool eq = (val==val2);
        bool stable = (order == order2);
        if (!eq) cout << "0 0" << '\n';
        else if (!stable) cout << "1 0" << '\n';
        else cout << "1 1" << '\n';
    }

}