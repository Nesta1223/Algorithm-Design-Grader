#include <bits/stdc++.h>
using namespace std;

int arr[100000];

void mergeSort(int l ,int r){
    if (l== r) return;
    int mid = (l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);

    vector<int> v1;
    vector<int> v2;

    for (int i= l ; i<= mid ;i++) v1.push_back(arr[i]);
    for (int i= mid + 1 ; i<= r ;i++) v2.push_back(arr[i]);

    int idx1 = 0;
    int idx2 = 0;
    vector<int> v;

    while (idx1 != v1.size() && idx2 != v2.size()){
        if (v1[idx1] <= v2[idx2]) {
            v.push_back(v1[idx1]);
            idx1++;
        }
        else{
            v.push_back(v2[idx2]);
            idx2++;       
        }
    }

    while (idx1 != v1.size()){
        v.push_back(v1[idx1]);
        idx1++;
    }
    while (idx2 != v2.size()){
        v.push_back(v2[idx2]);
        idx2++;
    }
    v1.clear();
    v2.clear();
    for (int i = l ; i<= r;i++){
        arr[i] = v[i-l];
    }
    return;

    
}

int main(){
    int n ; cin >> n;
    for (int i=1 ;i<= n; i++) cin >> arr[i];
    mergeSort(1,n);

    for (int i=1 ; i<= n ; i++){
        cout << arr[i] << " ";
    }

}