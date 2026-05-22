#include <iostream>
#include <set>
#include <list>
#include <vector>
using namespace std;

int main(){
    int n ; cin >> n;
    set<int> s;
    list<int> l;
    s.insert(1);
    int a = 99;
    while (a--){
        int b = *(s.begin());
        s.erase(s.begin());
        s.insert(2*b);
        s.insert(3*b);
    }
    cout << *(s.begin());
}