#include <bits/stdc++.h>
using namespace std;


int mss(const vector<int> &a,const int &start ,const int &stop ,const vector<int> &s){
    if (start == stop) return a[start];
    int m= (start+stop)/2;
    
    int r1 = mss(a,start,m,s);
    int r2 = mss(a,m+1,stop,s);

    int maxLeft = s[m]-s[m-1];
    // set<pair<int,int>> gLeft;
    for (int i= start; i<= m;i++){
        maxLeft = max(maxLeft,s[m]-s[i-1]);
        // gLeft.insert(make_pair(s[m]-s[i-1],m-i+1));
    }
    int maxRight = s[m+1]-s[m];
    for (int i= m+1 ; i<= stop; i++ ){
        maxRight = max(maxRight,s[i]- s[m]);
    }

    int r3 = maxLeft + maxRight;

    // for (int p=1;p<=m; p++){
    //     for (int q = m+1;q<=a.size()-1; q++){
    //         int sum = s[q] - s[p-1];
    //         if (sum > r3 ) r3 = sum;
    //     }
    // }
    return max(r1,max(r2,r3));
}




int main(){
    // Source - https://stackoverflow.com/q
// Posted by Kshitij Kohli, modified by community. See post 'Timeline' for change history
// Retrieved 2026-01-24, License - CC BY-SA 4.0

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<int> s(n+1);//quicksum
    int total = 0;
    for (int i=1;i<=n;i++){
        total += a[i];
        s[i] = total;
    }
    int x = mss(a,1,n,s);
    cout << x;
}