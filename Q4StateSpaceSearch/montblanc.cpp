    #include <bits/stdc++.h>
    using namespace std;
    // using int = long long;

    vector<int> rest(100005);
    // int rest[100100];

    int main(){
        // memset(rest, 1 ,sizeof rest);
        int n , d ;  cin >> n >> d;
        int goal ;
        for (int i=1;i<=n;i++){
            cin >> rest[i];
            if (i==n) goal = rest[i];
        }
        int l = 1;
        int r = rest[n];
        pair<int,int> ans;
        while(l<r){
            int mid = (l+r)/2;
            int step = mid;
            int go = 0 ;
            // auto it = upper_bound(rest.begin() + 1 , rest.begin()+n+1 , step);
            // it--;
            int cnt = 0;
            // cout << mid << "\n";
            while(go < goal && cnt<d){
                go += step;
                auto it = upper_bound(rest.begin()+1 , rest.begin()+n+1 , go);
                it--;
                go = *it;
                cnt++;
            }
            if (go<goal) l = mid+1;
            else if (cnt <= d && go==goal)  r = mid;
        }
        int go=0,cnt=0;
        while(go < goal && cnt<d){
            go += l;
            auto it = upper_bound(rest.begin()+1 , rest.begin()+n+1 , go);
            it--;
            go = *it;
            cnt++;
        }
        cout << l << " " << cnt;
    }