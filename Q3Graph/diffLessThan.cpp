#include <bits/stdc++.h>
using namespace std; 

int main(){
    vector<int> num;
    int n,d ; cin >> n >> d;
    for (int i=0;i<n;i++){
        int a; cin >> a;
        num.push_back(a);
    }
    sort(num.begin(),num.end());
    int left = 0;
    int right = 0;
    long long ans = 0;
    bool add = false;
    while( right <=  num.size()-1){
        while(left< right && num[right] - num[left] > d) left++;
        // cout << left << " " << right << endl;
        ans += right - left;
        right++;
        
    }
    // if (num[right] - num[left] <= d ) ans++;
    cout << ans;
    

}