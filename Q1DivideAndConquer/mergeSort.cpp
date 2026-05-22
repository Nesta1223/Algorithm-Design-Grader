#include <bits/stdc++.h>
using namespace std;

vector<int> MergeSort(vector<int> &now){
    if (now.size()<2) return now;
    int n = now.size();
    vector<int> left;
    vector<int> right;
    for (int i=0;i<n/2;i++) left.push_back(now[i]);
    for (int i=n/2;i<n;i++) right.push_back(now[i]);
    MergeSort(left);
    MergeSort(right);
    now.clear();
    int idx1 = 0;
    int idx2= 0;    
    while(!(idx1== left.size() || idx2 == right.size())){
        if (left[idx1] <= right[idx2]){
            now.push_back(left[idx1++]);
        }
        else{
            now.push_back(right[idx2++]);
        }
    } 
    while(idx2!=right.size()) now.push_back(right[idx2++]);
    while(idx1!=left.size()) now.push_back(left[idx1++]);

    return now;

}
int main(){
    int n; cin >> n;
    vector<int> p;
    while(n--) {
        int a; cin >> a;
        p.push_back(a);
    }
    MergeSort(p);
    for(auto i:p) cout << i << " ";
}