#include <bits/stdc++.h>
using namespace std;

int arr[100005];
vector<int> task[100005];

int main(){
    int n; int m; cin >> n >> m;
    for (int i=1;i<=m;i++){
        cin >> arr[i];
    }
    sort(arr+1,arr+m+1);
    for (int i=1;i<=n;i++){
        task[i].push_back(arr[i]);
    }
    for (int i=n+1;i<=m;i++){
        int idx = (i%n) +1;
        int b = task[idx].back();
        task[idx].push_back(b+arr[i]);
    }
    double sum = 0;
    double mm = m;
    for (int i=1;i<=n;i++){
        for (auto j: task[i]){
            sum+=j;
        }
    }
    // cout << sum << endl;

    double ans = sum/mm;
    cout << fixed << setprecision(3);
    cout << ans;

}