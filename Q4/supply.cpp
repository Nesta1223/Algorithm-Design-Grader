#include <bits/stdc++.h>
using namespace std;


struct supply{
    int day;
    int event;
    int label;
    bool operator< (const supply &s) const{
        return this->day < s.day;
    }
};


int main(){
    int n,m , k ; cin >> n >> m >> k;
    vector<supply> v;
    for (int i=1;i<=k;i++){
        int d,e , l ; cin >> d >> e >> l;
        v.push_back({d,e,l});
    }
    sort(v.begin() ,v.end());
    queue<int> plant;
    queue<int> store;
    for (auto s : v){
        if (s.event ==0) {
            if (store.size() ==0) {
                plant.push(s.label);
                cout << 0 << '\n';
            }
            else {
                int st = store.front();
                store.pop();
                cout << st << '\n';

            }
        }
        else if (s.event ==1) {
            if (plant.size() ==0) {
                store.push(s.label);
                cout << 0 << '\n';
            }
            else {
                int st = plant.front();
                plant.pop();
                cout << st << '\n';

            }
        }
    }

}