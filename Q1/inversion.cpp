#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSortReverse(vector<int> &now,int &count){
    if (now.size()<2) return now;
    vector<int> left;
    vector<int> right;
    int n = now.size();
    for (int i=0;i<n/2;i++) left.push_back(now[i]);
    for (int i=n/2;i<n;i++) right.push_back(now[i]);
    mergeSortReverse(left,count);
    mergeSortReverse(right,count);
    now.clear();
    int idx1 = 0;
    int idx2 = 0;
    while(!(idx1 == left.size() || idx2 == right.size())){
        if (left[idx1] > right[idx2]){
            count+= right.size() - idx2;
            now.push_back(left[idx1]);
            idx1++;
        }
        else{
            now.push_back(right[idx2]);
            idx2++;
        }
    }
    while(!(idx1 == left.size())) now.push_back(left[idx1++]);
    while(!(idx2== right.size())) now.push_back(right[idx2++]);
    return now;
}


int main(){
    int count = 0;
    int n; cin >>n;
    vector<int> v;
    while(n--) {
        int a ; cin >> a;
        v.push_back(a);
    }
    mergeSortReverse(v,count);
    // for (auto i : v) cout << i << " ";
    // cout << endl;
    cout << count;
}