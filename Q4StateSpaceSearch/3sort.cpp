#include <bits/stdc++.h>
using namespace std;


set<int> s1;
set<int> s2;
set<int> s3;
set<int> s12;
vector<int> v;

int threesort(int n,int one, int three){
    int cnt  =0;
    while(true){
        if (*(s3.begin())  == n-three) break;
        auto it = s3.begin();
        int idx3 = *it;
        // auto it2 = s1.lower_bound(idx3);
        if (idx3 < one){
            auto it3 = s1.end();
            it3--;
            int idx1 = *it3;
            swap(v[idx1],v[idx3]);
            s3.erase(it);
            s3.insert(idx1);
            s1.erase(it3);
            s1.insert(idx3);
        }
        else{
            auto it3 = s2.end();
            it3--;
            int idx1 = *it3;
            swap(v[idx1],v[idx3]);
            s3.erase(it);
            s3.insert(idx1);
            s2.erase(it3);
            s2.insert(idx3);
        }


        cnt++;
    }
    return cnt;

}

int twosort(int n, int twothree){
    int cnt  =0;
    while(true){
        if (*(s2.begin())  == n-twothree) break;
        auto it = s1.end();
        it--;
        int idx1 = *it;


        auto it2 = s2.begin();
        int idx2 = *it2;
        swap(v[idx1], v[idx2]);
        s1.erase(it);
        s2.erase(it2);
        s1.insert(idx2);
        s2.insert(idx1);
        cnt++;
    }
    return cnt;
}

int main(){
    int n ; cin >> n;
    int one = 0;
    int two = 0;
    int three = 0;
    for (int i=0;i<n;i++){
        int a; cin >> a;
        v.push_back(a);
        if (a==1) {
            one++;
            s1.insert(i);
            s12.insert(i);
        }
        if (a==2) {
            two++;
            s2.insert(i);
            s12.insert(i);
        }
        if (a==3) {
            s3.insert(i);
            three++;
        }

    }
    int x = threesort(n,one,three);
    int y = twosort(n,two+three);
    cout << x+y << endl;
    // for (int i=0;i<n;i++){
    //     cout << v[i] << " ";
    // }



}