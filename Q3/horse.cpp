#include <bits/stdc++.h>
using namespace std;


int arr[200005];

int main(){
    int n; cin >> n; 
    for (int i=1;i<=n;i++){
        cin >> arr[i];
    }
    set<pair<int,int>> s1;
    set<pair<int,int>> s2;
    s1.insert({arr[1],1});
    int sum1= arr[1];
    int sum2 = 0;


    // for (int i=1 ;i<=n;i++) cout << arr[i] << " ";
    // cout << endl;

    for (int i=2;i<=n;i++){
        int adder = arr[i];
        auto it = s1.begin();
        int minn = it->first;
        if (sum1 - minn + adder > sum2 + minn ){
            s2.insert({adder,i});
            sum2+=adder;
        }
        else{
            s1.insert({adder,i});
            sum1+=adder;
        }

        if (sum2 >= sum1){
            auto it = s2.begin();
            while (it != s2.end()){
                adder = it->first;
                if (sum1 + adder > sum2 -adder){
                    s1.insert({adder,it->second});
                    sum1+= adder;
                    s2.erase(it);
                    sum2-=adder;
                    break;
                }
                it++;
            }
        }

    }
    set<int> ans;
    for (auto i: s1){
        ans.insert(i.second);
    }
    cout << ans.size() << '\n';
    for (auto i: ans){
        cout << i << " ";
    }
}