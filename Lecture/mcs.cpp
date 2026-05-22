#include <bits/stdc++.h>
using namespace std;

vector<int> quickSum(vector<int> v){
    vector<int> s;
    int sum = 0;
    for (int i=0;i<v.size();i++){
        sum+= v[i];
        s.push_back(sum);
        // cout << sum << " ";

    }
    // cout << endl;
    return s;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    while (n--){
        int a ; cin >> a;
        v.push_back(a);
    }
    vector<int> s = quickSum(v);
    int max = INT_MIN;
    for (int i=0;i<s.size();i++){
        if(s[i] > max) max = s[i];
        for (int j=0;j<i;j++){
            if (s[i] - s[j] > max) max = s[i]-s[j];
        }
    }
    cout << max;

}